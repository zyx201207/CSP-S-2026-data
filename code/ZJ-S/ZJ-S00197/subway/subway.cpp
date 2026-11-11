#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e6+10;
constexpr int maxm=2e6+10;
constexpr int INF=1e18;
int c,n,m,d,q;
int w[maxn];
int s,t;
typedef struct edge
{
    int to,nxt,w;
    edge()=default;
    edge(int a,int b,int c):to(a),nxt(b),w(c){}
}edge;
edge es[maxm];
int heads[maxn];
int enums;
void add_edge(int u,int v,int w)
{
    es[++enums]={v,heads[u],w};
    heads[u]=enums;
}
int cnt[maxm];
int mxidx;
typedef struct node
{
    int p,dis;
    node()=default;
    node(int a,int b):p(a),dis(b){}
    bool operator<(const node &o)const
    {
        return dis>o.dis;
    }
}node;
int dis[maxn];
int vis[maxn];
void dijkstra(int s,int n)
{
    priority_queue<node> pq;
    for(int i=1;i<=n;++i)
    {
        vis[i]=0;
        dis[i]=INF;
    }
    dis[s]=0;
    pq.emplace(s,0);
    while(!pq.empty())
    {
        int u=pq.top().p;
        pq.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(int i=heads[u];i;i=es[i].nxt)
        {
            int v=es[i].to,w=es[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.emplace(v,dis[v]);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",&w[i]);
    }
    mxidx=m;
    for(int i=1;i<=n;++i)
    {
        int k;
        scanf("%lld",&k);
        int lst=0;
        for(int j=1;j<=k;++j)
        {
            int ai,ti;
            scanf("%lld %lld",&ai,&ti);
            ++cnt[ai];
            int p=m*cnt[ai]+ai;
            add_edge(ai,p,ti);
            add_edge(p,ai,ti);
            if(lst)
            {
                add_edge(p,lst,0);
                add_edge(lst,p,0);
            }
            lst=p;
            mxidx=max(mxidx,p);
        }
    }
    int x,y;
    while(q--)
    {
        scanf("%lld %lld",&x,&y);
        dijkstra(x,mxidx);
        int ans=dis[y]+w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
