#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, a[N], m;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int sum = a[1], ans = 0;
    for (int i = 1, j = 1; i <= n && j <= i; ) {
        // cout << i << ' ' << j << ' ' << sum << ' ' << (i - j + 1) * a[i] - sum << '\n';
        if ((i - j + 1) * a[i] - sum <= m) ans = max(ans, i - j + 1), ++i, sum += a[i];
        else sum -= a[j], ++j;
    }
    cout << ans << '\n';
    return 0;
}