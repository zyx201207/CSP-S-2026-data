#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 305;
int f[N], n, g[N];
ll a[N], d;
void solve() {
    int ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        g[i] = 1;
        for (int j = i + 1, l = i; j <= n; j++) {
            while (a[j] - a[l] > d) l++;
            if (l == j) break;
            f[j] = f[l] + 1;
            g[j] = 0;
            for (int k = l; k < j; k++) {
                if (f[j] == f[k] + 1) g[j] += g[k];
                if (g[j] > 2) {
                    g[j] = 3; break;
                }
            }
            if (g[j] == 2) ans++;
        }
    }
    cout << ans << endl;
}
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}