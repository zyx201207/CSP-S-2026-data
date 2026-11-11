#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, a[N], f[N], g[N], s[N], b[N], ans;
struct Node {
    int l, r;
}p[N];
void solve () {
    cin >> n >> d;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        p[i].l = p[i].r = - 1;
        int L = 1, R = i - 1, tmp = - 1;
        while (L <= R) {
            int mid = L + R >> 1;
            if (a[i] - a[mid] <= d) {
                tmp = mid, R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        if (tmp != - 1) {
            p[i].l = tmp, p[i].r = i - 1;
        }
    }
    ans = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= n; ++ j) {
            f[j] = n + 1;
            g[j] = b[j] = s[j] = 0;
        }
        g[i] = s[i] = 1, f[i] = 0, b[0] = i;
        for (int j = i + 1; j <= n; ++ j) {
            if (p[j].l == - 1 && p[j].r == - 1) continue;
            int L = max(p[j].l, i), R = p[j].r;
            f[j] = f[L] + 1;
            g[j] = s[b[f[L]]] - s[L - 1];
            b[f[j]] = j;
            s[j] = s[j - 1] + g[j];
            ans += (g[j] == 2);
        }
    }
    cout << ans << '\n';
    return ;
}
signed main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t --) solve();
    return 0;
}
