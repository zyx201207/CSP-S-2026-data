#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=1e17;
int c,n,m,d,q;
int w[M];
vector<vector<pair<int,long long> > >v(M);
long long dis[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1; i<=m; i++)
        scanf("%d",&w[i]);
    for(int i=1; i<=n; i++)
    {
        int k; scanf("%d",&k);
        while( k-- )
        {

            int a,t; scanf("%d%lld",&a,&t);
            v[a].push_back({i,t});
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            dis[i][j]=inf;
        dis[i][i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<v[i].size(); j++)
            for(int k=0; k<v[i].size(); k++)
            {
                int a1=v[i][j].first;long long t1=v[i][j].second;
                int a2=v[i][k].first;long long t2=v[i][k].second;
                dis[a1][a2]=min(t1+t2,dis[a1][a2]);
                dis[a2][a1]=min(t1+t2,dis[a1][a2]);
            }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                dis[j][k]=min( dis[j][k],dis[j][i]+dis[i][k] );
    while( q-- )
    {
        int x,y; scanf("%d%d",&x,&y);
        long long ans=inf;
        for(int i=0; i<v[x].size(); i++)
            for(int j=0; j<v[y].size(); j++)
            {
                int a1=v[x][i].first,a2=v[y][j].first;
                long long t1=v[x][i].second,t2=v[y][j].second;
                ans=min( ans,dis[a1][a2]+t1+t2 );
            }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
