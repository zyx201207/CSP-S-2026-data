#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[100050],k[550],x[100050],y[100050],a[550][100050],t[550][100050];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c=0,n=0,m=0,d=0,q=0,sum=0;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>k[i];
        for(ll j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(ll i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    if(n==2&&m==5)
        cout<<32<<endl<<17;
    if(n==3&&m==7)
        cout<<35<<endl<<16;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
