#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long dt[1111][1111];
long long w[1111];
long long su[1111][1111];
long long dis[1111][1111];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dt[i][j]=1e17;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int k=1;k<=n;k++)
    {
        long long x;
        cin>>x;
        for(int i=1;i<=x;i++) cin>>su[k][i]>>dis[k][i];
        for(int i=1;i<x;i++)
        {
            int u=su[k][i];
            for(int j=i+1;j<=x;j++)
            {
                int v=su[k][j];
                long long cost=dis[k][i]+dis[k][j];
                dt[u][v]=min(dt[u][v],cost);
                dt[v][u]=min(dt[v][u],cost);
            }
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dt[i][j]=min(dt[i][j],dt[i][k]+dt[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+dt[u][v]<<"\n";
    }
    return 0;
}
