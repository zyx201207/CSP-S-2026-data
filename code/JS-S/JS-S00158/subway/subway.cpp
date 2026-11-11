#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=510;
const int MAXM=1010;
long long INF=1e18+10;

int c,n,m,d,q;
int w[MAXM];
int cost[MAXN][MAXM];
int dis[MAXM][MAXM];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cost[i][j]=INF;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            dis[i][j]=INF;
    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        int v,o;
        for(int j=1;j<=k;j++)
        {
            cin>>v>>o;
            cost[i][v]=o;
        }
    }
    for(int i=1;i<=m;i++)
        for(int k=1;k<=n;k++)
        {
            if(cost[k][i]==INF)
                continue;
            for(int j=1;j<=m;j++)
            {
                if(cost[k][j]==INF||i==j)
                    continue;
                dis[i][j]=min(dis[i][j],cost[k][i]+cost[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    for(int i=1;i<=m;i++)
        for(int k=1;k<=m;k++)
        {
            if(dis[i][k]==INF)
                continue;
            for(int j=1;j<=m;j++)
            {
                if(dis[k][j]==INF||i==j)
                    continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    int x,y;
    while(q--)
    {
        cin>>x>>y;
        int ans=dis[x][y]+w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}

