#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f[2000][2000],x,u,v,a[1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=1e9;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>f[i][i+m];
        f[i+m][i]=f[i][i+m];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        for(int j=1;j<=x;j++)
        {
            cin >> u >> v;
            a[j]=u;
            f[2*m+i][u]=f[u][2*m+i]=v;
        }
        for(int j=1;j<=x;j++)
        {
            for(int k=1;k<j;k++)
            {
                f[a[j]][a[k]]= f[a[k]][a[j]]=f[a[k]][2*m+i]+f[2*m+i][a[j]];
            }
        }

    }
    for(int i=1;i<=m;i++)
    {
        f[i][i]=1;
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin >> u >> v;
        cout << f[u][v]+f[u][u+m]+f[v][v+m] <<'\n';
    }
    return 0;
}

