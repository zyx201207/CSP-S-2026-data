#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e6+5;ll a[N];
int c,t;

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) {
        ll n,d;
        cin>>n>>d;

        for(ll i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for(ll i=1;i<=n-2;i++) {
            ll j=min(2*d,n-i);
            ll zs=(j-1)/2;
            ll cnt;
            if((j-1)%2) {
                cnt=(1+zs)*zs+1;
            }
            else {
                cnt=(1+zs)*zs;
            }
            ll x=cnt*(j-1)/2;
            if(x==2) ans++;
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
