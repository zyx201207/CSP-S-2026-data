// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 5e5 + 2, kMaxM = 502, kMaxD = 22;
const LL kP = 1e9 + 7;

LL cT, n, m, k, cD, q, a[kMaxN], ans, d[kMaxM][kMaxM], cnt[kMaxN];
pair<LL, LL> f[kMaxN][kMaxD];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    cin >> cT >> n >> m >> cD >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = (i == j ? 0 : 1e18);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1, p, x; j <= k; j++) {
            cin >> p >> x, f[p][++cnt[p]] = {i, x};
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int l = 1; l <= cnt[i]; l++) {
            for (int r = l + 1; r <= cnt[i]; r++) {
                int x = f[i][l].first, y = f[i][r].first;
                d[y][x] = d[x][y] = min(d[x][y], f[i][l].second + f[i][r].second);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int l, r; q; q--) {
        cin >> l >> r, ans = 1e18;
        for (int i = 1; i <= cnt[l]; i++) {
            for (int j = 1; j <= cnt[r]; j++) {
                ans = min(ans, d[f[l][i].first][f[r][j].first] + f[l][i].second + f[r][j].second);
            }
        }
        cout << ans + a[l] + a[r] << '\n';
    }
    return 0;
}
// g++ subway.cpp -o subway -O2 -static -Wall && time ./subway