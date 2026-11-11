#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=1e3+10;
constexpr int INF=1e18;
int c,t,n,k;
vector<int> gra[maxn];
int vis[maxn],f[maxn];
void dfs1(int u,int p)
{
    vis[u]=1;
    for(auto& v:gra[u])
    {
        if(v==p) continue;
        if(f[v]) dfs1(v,u);
    }
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        for(int i=1;i<=n;++i) gra[i].clear();
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<n;++i)
        {
            int u,v;
            scanf("%lld%lld",&u,&v);
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        int res=1e18;
        for(int i=0;i<(1<<n);++i)
        {
            fill(f,f+1+n,0);
            fill(vis,vis+1+n,0);
            int cnt=0;
            vector<int> s;
            for(int j=0;j<n;++j)
            {
                if(i>>j&1) ++cnt,s.emplace_back(j+1),f[j+1]=1;
            }
            if(cnt!=k) continue;
            cnt=0;
            for(auto& v:s)
            {
                if(!vis[v]) 
                {
                    dfs1(v,0);
                    ++cnt;
                }
            }
            if(cnt>2) continue;
            queue<int> q;
            vector<int> dis(n+1,INF);
            for(auto& v:s) q.emplace(v),dis[v]=0;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto& v:gra[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        q.emplace(v);
                    }
                }
            }
            int ans=0;
            for(int j=1;j<=n;++j) ans=max(ans,dis[j]);
            res=min(res,ans);
        }
        printf("%lld",res);
        printf("\n");
    }
    return 0;
}