#include <bits/stdc++.h>
using namespace std;

int w[500005];

int dis[5005][5005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int qi;
        for(int j=1;j<=k;j++)
        {
            int t,r;
            cin>>t>>r;
            if(dis[t][t+m]!=0x3f3f3f3f)
            {
                dis[t][t+m+1]=r;
                dis[t+m+1][t]=r;
            }
            else
            {
                dis[t][t+m]=r;
                dis[t+m][t]=r;
            }
            if(j!=1)
            {
                dis[qi][t+m]=0;
            }
            qi=t+m;
        }
    }
    for(int k=1;k<=m*2+1;k++)
    {
        for(int i=1;i<=m*2+1;i++)
        {
            for(int j=1;j<=m*2+1;j++)
            {
                if(dis[i][k]!=0x3f3f3f3f&&dis[k][j]!=0x3f3f3f3f)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<dis[u][v]+w[u]+w[v]<<'\n';
    }
    return 0;
}
