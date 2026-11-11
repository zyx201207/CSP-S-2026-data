#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], pre[N];

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i]; sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = 0, l = 1;
    for (int r = 1; r <= n; r++) {
        while (a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) > m) l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) Solve();
    return 0;
}
