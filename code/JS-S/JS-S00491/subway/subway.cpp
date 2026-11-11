#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
long long w[500005],k[500005],a[500005][500005],t[500005][500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int r=1;r<=q;r++)
    {
        long long ans;
        cin>>x>>y;



        cout<<ans<<endl;
    }
    return 0;
}
