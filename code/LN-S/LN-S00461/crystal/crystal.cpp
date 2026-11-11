#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005];
ll sum[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (ll r = 2; r <= n; r++) {
        sum[r] = sum[r - 1] + r * (a[r] - a[r - 1]);
    }
    ll l = 1, ans = 1;
    for (ll r = 2; r <= n; r++) {
        while (sum[r] - sum[l - 1] - (l - 1) * (a[r] - a[l - 1]) > m) ++l;
        ans = max(ans, r - l + 1 + (l != 1));
    }
    cout << ans;

    return 0;
}
