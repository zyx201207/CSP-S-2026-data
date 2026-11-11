#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N];
void solve(){
    ll n,d,cnt=0;
    cin>>n>>d;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
            ll sum=0;
        for(ll j=i+1;j<=n;j++){
            if(a[j]<=a[i]+d)sum++;
        }
        if(sum==2)cnt++;
    }
    cout<<cnt-1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
