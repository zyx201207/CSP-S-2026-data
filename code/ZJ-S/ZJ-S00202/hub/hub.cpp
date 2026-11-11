#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=0x3f3f3f3f3f3f3f3f;
#ifdef D
#define debug(i) cerr<<"Line:"<<__LINE__<<','<<#i<<'='<<i<<'\n'
#define debug2(i,j) cerr<<"Line:"<<__LINE__<<','<<#i<<'='<<i<<','<<#j<<'='<<j<<'\n'
#define debug3(i,j,k) cerr<<"Line:"<<__LINE__<<','<<#i<<'='<<i<<','<<#j<<'='<<j<<','<<#k<<'='<<k<<'\n'
#else 
#define debug(i) (void(0))
#define debug2(i,j) (void(0))
#define debug3(i,j,k) (void(0))
#endif
namespace solver1
{
    constexpr int maxn=100+1;
    vector<int>gra[maxn];
    int col[maxn];
    int dis[maxn][maxn];
    bool vis[maxn];
    void solve()
    {
        int n,k;
        cin>>n>>k;
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;++i)gra[i].clear();
        for(int i=2,u,v;i<=n;++i)
        {
            cin>>u>>v;
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        auto bfs=[&](int s)
        {
            memset(vis,0,sizeof(vis));
            queue<int>q;
            dis[s][s]=0;
            q.emplace(s);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                if(vis[u])continue;
                vis[u]=1;
                for(int v:gra[u])
                {
                    if(dis[s][v]>dis[s][u]+1)
                    {
                        dis[s][v]=dis[s][u]+1;
                        q.emplace(v);
                    }
                }
            }
        };
        for(int i=1;i<=n;++i)bfs(i);
        int full=1<<n;
        int ans=INF;
        for(int st=0;st<full;++st)
        {
            if(__builtin_popcountll(st)!=k)continue;
            for(int i=0;i<n;++i)col[i+1]=st>>i&1;
            auto bfs2=[&](int s)
            {
                queue<int>q;
                q.emplace(s);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    col[u]=0;
                    for(int v:gra[u])
                    {
                        if(col[v])q.emplace(v);
                    }
                }
            };
            int cnt=0;
            for(int i=1;i<=n;++i)
            {
                if(col[i]==0)continue;
                ++cnt;
                if(cnt==3)break;
                bfs2(i);
            }
            if(cnt==3)continue;
            debug(st);
            int tmp=0;
            for(int i=1;i<=n;++i)
            {
                int cur=INF;
                for(int j=0;j<n;++j)
                    if(st>>j&1)
                    {
                        cur=min(cur,dis[i][j+1]);
                        debug3(i,j,dis[i][j+1]);
                    }
                debug2(i,cur);
                tmp=max(tmp,cur);
            }
            debug(tmp);
            ans=min(ans,tmp);
        }
        cout<<ans<<'\n';
    }
}
signed main()
{
#ifndef zzr
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)solver1::solve();
}
// 1-5`
// 0 1
// 9 3
// 1 2
// 2 8
// 4 7
// 6 5
// 7 9
// 8 5
// 5 3
// 3 9