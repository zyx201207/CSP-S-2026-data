#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e5 + 5;

ll a[N], n, m, sum[N];

bool solve(ll l, ll r) {
    ll o = sum[r] - sum[l - 1];
    ll w = a[r] * (r - l + 1);
    w -= o;
    return (w <= m);
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i]; 
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll l = 1, r = i;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (solve(mid, i)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}