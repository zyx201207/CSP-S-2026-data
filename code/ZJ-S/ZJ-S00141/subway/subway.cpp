#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iny signed long long
constexpr int maxn=5e2+13;
constexpr int maxm=5e5+13;

int c,n,m,d,Q;
int w[maxm];
vector<pair<int,int>>idx[maxm];
ll dis[maxn][maxn];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
    //最小总步行时间
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&w[i]);
    }
    //应该根据n跑最短路，查询时枚举两个点属于哪条路线
    //(5e5/20)*400=5e5*20=1e7
    for(int i=1;i<=n;++i)
    {
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int a,t;
            scanf("%d%d",&a,&t);
            idx[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dis[i][j]=1e18;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;++i)
    {
        int siz=idx[i].size();
        for(int j=0;j<siz;++j)
        {
            for(int l=0;l<siz;++l)
            {
                int id1=idx[i][j].first,id2=idx[i][l].first;
                int t=idx[i][j].second+idx[i][l].second;
                dis[id1][id2]=min(dis[id1][id2],1ll*t);
                dis[id2][id1]=dis[id1][id2];
            }
        }
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            if(dis[i][k]==1e18)
            {
                continue;
            }
            for(int j=1;j<=n;++j)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=1e18;
        for(pair<int,int>&i:idx[x])
        {
            for(pair<int,int>&j:idx[y])
            {
                ans=min(ans,dis[i.first][j.first]+i.second+j.second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }

    return 0;
}

