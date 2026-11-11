#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, a[500009], s[500009];

bool ok(ll u) {
    ll r = 0x3f3f3f3f3f3f3f3f;
    for(ll i = 1; i <= n-u+1; i++) {
        r = min(r, a[i+u-1]*u-(s[i+u-1]-s[i-1]));
    }
    return (r <= m);
}

/**
 * 他还有温柔的倔强 还有琳琅诗行 咬着牙走在路上
 */

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(ll i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
    ll l = 0, r = n, ans = 0;
    while(l <= r) {
        ll mid = (l+r)>>1;
        if(ok(mid)) l = mid+1, ans = mid;
        else r = mid-1;
    }
    cout << ans << '\n';
    return 0;
}