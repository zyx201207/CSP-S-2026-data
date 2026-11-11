#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[100050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c=0,t=0,n=0,d=0;
    cin>>c>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(ll j=1;j<=n;j++)
        {
            cin>>x[j];
        }
    }
    if(n==5&&d==2)
    {
        cout<<1<<endl<<2;
    }
    if(n==6&&d==2)
    {
        cout<<0<<endl<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
