#include<bits/stdc++.h>
using namespace std;
int const N=500;
long long const M=2e9+10;
long long c,n,m,d,q,w[N],a[N][N],t[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //cout<<"apple";
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=M;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            t[j]=M;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            t[x]=y;
        }
        for(int j=1;j<=m;j++)
            for(int p=j+1;p<=m;p++)
            {
                a[j][p]=min(a[j][p],t[j]+t[p]);
                a[p][j]=a[j][p];
            }
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }*/
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<a[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
