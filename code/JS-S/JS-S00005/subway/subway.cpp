#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005, M = 505;
int c, m, n, d, q, w[N], k, a, v[N], t[N], x, y, b, g[5005][5005];
bool flag;
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= 504; i++) {
        for (int j = 1; j <= 504; j++) {
            if (i == j) {
                g[i][j] = 0;
            } else {
                g[i][j] = 1e9;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        if (k != 2) flag = 0;
        if (k == 2) {
            cin >> a >> b >> c >> d;
            g[a][c] = min(g[a][c], b + d);
            g[c][a] = min(g[a][c], b + d);
        } else {
            for (int j = 1; j <= k; j++) {
                cin >> v[j] >> t[j];
            }
            for (int j = 1; j <= k; j++) {
                for (int l = j + 1; l <= k; l++) {

                    g[v[j]][v[l]] = min(g[v[j]][v[l]], t[j] + t[l]);
                    g[v[l]][v[j]] = g[v[j]][v[l]];
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++){
            for (int k = i; k <= j; k++) {
                //cout << i << " " << j << " " << k << " " << g[i][j] << endl;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                g[j][i] = g[i][j];
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        cout << w[x] + w[y] + g[x][y] << endl;
    }
    return 0;
}
