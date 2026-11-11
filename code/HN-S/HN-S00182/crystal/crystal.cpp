#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 7;
int n, m, ans, a[N], s[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    for (int l = 1, r = 1; l <= n; ++l) {
        while (r <= n && (r - l + 1) * a[r] - s[r] + s[l - 1] <= m) ++r;
        ans = max(ans, r - l);
    }
    cout << ans;
    return 0;
}