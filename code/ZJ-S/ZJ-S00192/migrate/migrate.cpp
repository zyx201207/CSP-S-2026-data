#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e6+10;
constexpr int maxm=5e3+10;
constexpr int INF=1e18;
int n,c,T,d,ans,x[maxn],cnt[maxm][maxm],dis[maxn];
vector<int>gra[maxn];
void bfs(int s)
{
    for(int i=1;i<=n;++i)
    {
        dis[i]=INF;
    }
    queue<int>q;
    q.emplace(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:gra[u])
        {
            if(dis[v]>dis[u]+1)
            {
                cnt[s][v]=1;
                dis[v]=dis[u]+1;
                q.emplace(v);
            }
            else if(dis[v]==dis[u]+1)
            {
                ++cnt[s][v];
            }
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&d);
        ans=0;
        for(int i=1;i<=n;++i)
        {
            gra[i].clear();
            for(int j=1;j<=n;++j)
            {
                cnt[i][j]=0;
            }
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&x[i]);
            for(int j=1;j<i;++j)
            {
                if(x[i]-x[j]<=d)
                {
                    gra[i].emplace_back(j);
                    gra[j].emplace_back(i);
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            bfs(i);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(cnt[i][j]==2)
                {
                    ++ans;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
