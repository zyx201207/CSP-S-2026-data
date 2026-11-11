#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e2+10;
constexpr int maxm=5e5+10;
constexpr int INF=1e18;
int c,n,m,d,q,w[maxm],k[maxn],idx,dis[maxn][maxn];
vector<pair<int,int>> gra1[maxm];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",w+i);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",k+i);
        ++idx;
        for(int j=1;j<=k[i];++j)
        {
            int a,t;
            scanf("%lld%lld",&a,&t);
            gra1[a].emplace_back(idx,t);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dis[i][j]=(i==j)?0:INF;
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(auto& [v,t]:gra1[i])
        {
            for(auto& [vv,tt]:gra1[i])
            {
                dis[v][vv]=min(dis[v][vv],t+tt);
                dis[vv][v]=min(dis[vv][v],t+tt);
            }
        }
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int res=INF;
        for(auto& [v,t]:gra1[x])
        {
            for(auto& [vv,tt]:gra1[y])
            {
                res=min(res,dis[v][vv]+w[x]+w[y]+t+tt);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}