#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=0x3f3f3f3f3f3f3f3f;
namespace solver1// n*n
{
    void solve()
    {
        int n,d;
        cin>>n>>d;
        vector<int>x(n+1);
        for(int i=1;i<=n;++i)cin>>x[i];
        vector<vector<int>>gra(n+1);
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
                if(x[j]-x[i]<=d)
                {
                    gra[i].emplace_back(j);
                }
        vector<int>dis(n+1);
        vector<int>vis(n+1);
        vector<int>cnt(n+1);
        auto bfs=[&](int s)->int
        {
            fill(dis.begin(),dis.end(),INF);
            fill(vis.begin(),vis.end(),0);
            fill(cnt.begin(),cnt.end(),0);
            queue<int>q;
            q.emplace(s);
            dis[s]=0;
            cnt[s]=1;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                if(vis[u])continue;
                vis[u]=1;
                for(int v:gra[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        cnt[v]=cnt[u];
                        q.emplace(v);
                    }
                    else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
                }
            }
            int ans=0;
            for(int i=s;i<=n;++i)
            {
                ans+=cnt[i]==2;
            }
            return ans;
        };
        int ans=0;
        for(int i=1;i<=n;++i)ans+=bfs(i);
        cout<<ans<<'\n';
    }
};
signed main()
{
#ifndef zzr
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    if(c<=10)while(t--)solver1::solve();
    else cout<<0;
}
// 1-5`