#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 5;
int a[N], n, m, ans;
// a < 2^30
bool can[N];
void solve() {
    for (int i = 28; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!can[j]) continue;
            if (a[j] >> i & 1) ++cnt;
        }
        if (cnt < m) continue;
        for (int j = 1; j <= n; j++) {
            if (!(a[j] >> i & 1)) can[j] = 0;
        }
    }
}
int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(can + 1, can + n + 1, true);
    for (int i = 1; i <= n; i++) cin >> a[i];
    solve();
    ans = (1 << 30) - 1;
    for (int i = 1, cnt = 0; i <= n, cnt < m; i++) {
        if (can[i]) {
            ans &= a[i];
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}