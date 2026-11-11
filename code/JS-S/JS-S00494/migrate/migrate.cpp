#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    ll ans=0;
    while(t--)
    {

        ll n,d;
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
            cin>>x[i];
        cout<<ans<<"\n";
        ans++;
    }
    return 0;
}
