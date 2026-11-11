#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;

ll n, m, a[N], ans, c[N];

bool check(ll x){
    queue<ll> q;
    for (int i = 1; i <= x; i++) q.push(a[i]);
    ll sum = 0, last = a[x];
    for (int i = 1; i < x; i++) sum+=(a[x]-a[i]);
    for (int i = x+1; i <= n; i++){
        if (sum<=m) return true;
        ll t = q.front();
        sum-=(last-t);
        sum+=(x-1)*(a[i]-last);
        last = a[i];
        q.pop();
        q.push(a[i]);
    }
    if (sum<=m) return true;
    return false;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll l = 1, r = n, mid;
    while (l<=r){
        mid = (l+r)>>1;
        if (check(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans;
    return;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
