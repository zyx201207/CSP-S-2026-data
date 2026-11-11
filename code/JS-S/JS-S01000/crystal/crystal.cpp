#include<bits/stdc++.h>
using namespace std;//zha diao le
typedef long long ll;
const ll N=5e5+10;
ll a[N];
ll n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll ans=-1;
    for(ll i=1;i<=n;i++){
        ll left=m;
        ll cnt=1;
        for(ll j=1;j<i;j++){
            if(left>=(a[i]-a[j])){
                left-=(a[i]-a[j]);
                cnt++;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans<<endl;
    return 0;
}
