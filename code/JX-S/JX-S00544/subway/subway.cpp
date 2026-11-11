#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[501],x[100001]={},y[100001]={};
long long w[500001]={},a[501][500001]={},t[501][500001]={};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int v=1;v<=m;v++)
    {
        cin>>w[v];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;r++)
    {
        cin>>x[r]>>y[r];
    }
    return 0;
}
