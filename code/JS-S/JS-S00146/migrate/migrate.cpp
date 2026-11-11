#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t;
ll a[N];

void solve(){
    ll n,d;
    cin>>n>>d;
    map<ll,ll> mp;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    ll h=a[2]-a[1];
    ll ab=d/h;
    ab*=h;
    ll dis=ab+ab-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(mp[a[i]+dis]) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    freopen("migrate4.in","r",stdin);
    freopen("migrate4.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
