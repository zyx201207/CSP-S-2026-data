#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;
ll d;
ll n,m;
ll a[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1,a+1+n,greater<ll>());
    ll l = 1, r = 1;
    ll cnt = 0;
    for(; l <= n; ++l){
        cnt-=(r-l)*(a[l-1]-a[l]);
        for(; r <= n; ++r){
            if(cnt+a[l]-a[r] > m) break;
            cnt+=a[l]-a[r];
        } 
        ans = max(ans,r-l);
    }
    cout << ans << endl;
    return 0;
}