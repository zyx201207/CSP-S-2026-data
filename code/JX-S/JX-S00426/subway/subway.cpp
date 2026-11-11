#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[505][5005],t[505][5005],k[505],x[100005],y[100005],dist[5005][5005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            dist[i][j]=t[j][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]==0||dist[k][j]==0)
                    continue;
                if(dist[i][j]==0)
                    dist[i][j]=dist[i][k]+dist[k][j];
                else dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        cout<<dist[x[i]][y[i]]+w[x[i]]+w[y[i]]+t[x[i]][2]+t[y[i]][1]<<"\n";
    }
    return 0;
}
