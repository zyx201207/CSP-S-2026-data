#include<bits/stdc++.h>
using namespace std;
long long a[501][500001],t[501][500001],k[501],w[500001],ans,across,across_t,c,d,m,n,q,tmp,t2,x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)cin>>w[i];
    for(long long i=1;i<=n;i++){cin>>k[i];for(long long j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];}
    for(long long i=1;i<=m;i++)for(long long j=1;j<=n;j++)for(long long k2=1;k2<=k[j];k2++)if(a[j][k2]==i){across=i,across_t=j;break;}
    for(long long i=1;i<=q;i++)
    {
        cin>>x>>y;
        for(long long j=1;j<=n;j++)for(long long k2=1;k2<=k[j];k2++)if(a[j][k2]==x){tmp=j;break;}
        for(long long j=1;j<=n;j++)for(long long k2=1;k2<=k[j];k2++)if(a[j][k2]==y){t2=j;break;}
        ans=w[x]+t[tmp][x]+w[y];
        if(tmp==t2)cout<<ans+t[tmp][y];
        else cout<<ans+t[tmp][across]+t[across_t][across]+t[across_t][y];
        ans=0;
    }
    return 0;
}
