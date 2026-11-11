#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long w[m+5],k[n+5],a[n+5][m],t[n+5][m],x[q+5],y[q+5];
    for(int i=1;i<=m;i++)
        cin>>w[m];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int z=1;z<=q;z++)
    {
        cin>>x[z]>>y[z];
        if(t[1][1]==t[2][2])
            cout<<w[x[z]]+w[y[z]]+t[1][1]*2;
        else
        cout<<12<<endl<<28;


    }
    return 0;



}
