#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e7+10;
constexpr int INF=(LLONG_MAX>>1)-1ll;
int c,n,m,d,q;
int w[maxn];
typedef struct node
{
    int p,d;
    node()=default;
    node(int a,int b):p(a),d(b){}
    bool operator<(const node &o) const
    {
        return d>o.d;
    }
}node;
vector<node> gra[maxn];
bool vis[maxn];
int dis[maxn];
int pnum;
void dijkstra(int s)
{
    for(int i=0;i<=pnum;++i)
    {
        vis[i]=0;
        dis[i]=INF;
    }
    priority_queue<node> q;
    q.emplace(node(s,0ll));
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().p;
        q.pop();
        if(vis[u])
        {
            continue;
        }
        vis[u]=1;
        for(auto &i:gra[u])
        {
            int v=i.p;
            int w=i.d;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(node(v,dis[v]));
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",w+i);
    }
    pnum=m+n;
    for(int i=1,k;i<=n;++i)
    {
        scanf("%lld",&k);
        for(int j=1,a,t;j<=k;++j)
        {
            scanf("%lld%lld",&a,&t);
            ++pnum;
            gra[pnum].emplace_back(node(a,t));
            gra[a].emplace_back(node(pnum,t));
            gra[m+i].emplace_back(node(pnum,0ll));
            gra[pnum].emplace_back(node(m+i,0ll));
        }
    }
    for(int i=1,s,t;i<=q;++i)
    {
        scanf("%lld%lld",&s,&t);
        dijkstra(s);
        int ans=dis[t]+w[s]+w[t];
        printf("%lld\n",ans);
    }
    return 0;
}

