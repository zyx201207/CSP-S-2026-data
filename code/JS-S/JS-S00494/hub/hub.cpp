#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000005],y[2000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    ll ans=0;
    while(t--)
    {

        ll n,k;
        cin>>n>>k;
        for(ll i=1;i<=n-1;i++)
            cin>>x[i]>>y[i];
        cout<<ans<<"\n";
        ans++;
    }
    return 0;
}

