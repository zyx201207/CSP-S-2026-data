#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e2+10;
constexpr int maxm=5e5+10;
constexpr int inf=(LLONG_MAX>>1)-1ll;
int w[maxm],k[maxn];
int dis[maxn][maxn];
vector<pair<int,int>> fa[maxm];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    int c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;++i)
    {
        dis[i][i]=0;
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];++j)
        {
            int a,t;
            scanf("%lld%lld",&a,&t);
            if(!fa[a].empty())
            {
                for(pair<int,int> b:fa[a])
                {
                    int v=b.first,x=b.second;
                    dis[i][v]=min(dis[i][v],x+t);
                    dis[v][i]=dis[i][v];
                }
            }
            fa[a].emplace_back(i,t);
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
        int x,y,ans=inf;
        scanf("%lld%lld",&x,&y);
        for(pair<int,int> a:fa[x])
        {
            for(pair<int,int> b:fa[y])
            {
                int u=a.first,v=b.first,w1=a.second,w2=b.second;
                ans=min(ans,dis[u][v]+w[x]+w[y]+w1+w2);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}