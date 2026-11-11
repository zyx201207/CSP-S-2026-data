#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 9;
int n;
ll m;
ll a[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll l = 1, r = 2, ans = 0;
    while (r <= n) {
        ll x = 1ll * (r - l) * (a[r] - a[r - 1]);
        if (x <= m) ++r, m -= x;
        else {
            m += a[r - 1] - a[l];
            ++l;
        }
        ans = max(ans, r - l);
    }
    cout << ans;
    return 0;
}
/*
write sth?

I often find myself lingering in the past...

huh? what are you waitting for?
*/
