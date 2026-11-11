#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,t;

constexpr int maxn=5e5+10;

int x[maxn];

int n,d;

typedef struct edge
{
    int to,nxt,wei;
    edge()=default;
    edge(int a,int b,int c):to(a),nxt(b),wei(c) {}
}edge;

edge es[maxn];
int heads[maxn];
int enums;

constexpr int INF=LLONG_MAX>>1;

int dis[maxn];
bool vis[maxn];

typedef struct node
{
    int x,wei;
    bool operator<(const node&a)const
    {
        return wei>a.wei;
    }
}node;

inline void add_edge(int x,int y,int wei)
{
    es[++enums]={y,heads[x],wei};
    heads[x]=enums;
}

priority_queue<node> q;

inline void dij()
{
    fill(dis,dis+n+1,INF);
    q.push({1,0});
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.top().x;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=heads[u];i;i=es[i].nxt)
        {
            int v=es[i].to;
            int wei=es[i].wei;
            if(dis[v]>dis[u]+wei)
            {
                dis[v]=dis[u]+wei;
                q.push({v,dis[v]});
            }
        }
    }
}

unordered_map<int,bool> mp;

inline void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    int ans=0;
    dij();
    for(int i=1;i<=n;++i)
    {
        if(mp[dis[i]]==1) ++ans;
        mp[dis[i]]=1;
    }
    cout<<ans/2<<'\n';
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
