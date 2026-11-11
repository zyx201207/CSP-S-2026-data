#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=1e6+10;
constexpr int INF=1e18;
int n,m,ans[maxn],c,d,q,w[maxn],t[maxn],dis[maxn],id;
bool vis[maxn];
struct node 
{
    int v,dis;
    node()=default;
    node(int a,int b):v(a),dis(b){}
    bool operator<(const node &o)const
    {
        return dis<o.dis;
    }
};
vector<node>gra[maxn];
struct query
{
    int t,i;
    query()=default;
    query(int a,int b):t(a),i(b){}
};
vector<query>qry[maxn];
void dij(int n,int s)
{
    for(int i=1;i<=n;++i)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    priority_queue<node>q;
    q.emplace(s,0);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u])
        {
            continue;
        }
        vis[u]=1;
        for(auto [v,w]:gra[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(v,dis[v]);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    id=m;
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1,k;i<=n;++i)
    {
        scanf("%lld",&k);
        for(int j=1,a,t,lt;j<=k;++j)
        {
            scanf("%lld%lld",&a,&t);
            ++id;
            gra[a].emplace_back(id,t);
            gra[id].emplace_back(a,t);
            if(j!=1)
            {
                gra[lt].emplace_back(id,0);
                gra[id].emplace_back(lt,0);
            }
            lt=id;
        }
    }
    for(int i=1,x,y;i<=q;++i)
    {
        scanf("%lld%lld",&x,&y);
        qry[x].emplace_back(y,i);
    }
    for(int s=1;s<=m;++s)
    {
        if(qry[s].empty())
        {
            continue;
        }
        dij(id,s);
        for(auto [t,i]:qry[s])
        {
            ans[i]=dis[t]+w[s]+w[t];
        }
    }
    for(int i=1;i<=q;++i)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
