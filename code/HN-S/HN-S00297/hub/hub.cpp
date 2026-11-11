#include<bits/stdc++.h>

constexpr int N=30;

std::vector<int>tree[N+5];
bool color[15];

void dfs(int u)
{
    color[u]=0;
    for(int v:tree[u])if(color[v])dfs(v);
}

int dist(int u)
{
    std::queue<int>q;
    q.push(u);
    int dis[15]{};
    while(q.size())
    {
        int u=q.front();q.pop();
        if(color[u])return dis[u];
        for(int v:tree[u])if(!dis[v])dis[v]=dis[u]+1,q.push(v);
    }
    return -1;
}

void sol()
{
    int n,k;
    std::cin>>n>>k;
    for(int i=1;i<=n;++i)tree[i].clear();
    for(int i=1;i<n;++i)
    {
        int u,v;
        std::cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int ans=1145;
    for(int i=1;i<(1<<n);++i)
    {
        if(__builtin_popcount(i)!=k)continue;
        auto check=[i,n]()
        {
            for(int j=1;j<=n;++j)color[j]=(i>>(j-1)&1);
            int num=0;
            for(int j=1;j<=n;++j)if(color[j])++num,dfs(j);
            return num<=2;
        };
        if(!check())continue;
        for(int j=1;j<=n;++j)color[j]=(i>>(j-1)&1);
        int max=0;
        for(int j=1;j<=n;++j)
            max=std::max(max,dist(j));
        ans=std::min(ans,max);
    }
    std::cout<<ans<<'\n';
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    freopen("hub.log","w",stderr);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    int c,t;
    std::cin>>c>>t;
    while(t--)sol();
}