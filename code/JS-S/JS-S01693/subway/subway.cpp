#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[10005];
struct line {
    int sum;
    int to[10005];
    int t[10005];
} l[10005];
int g[10005][10005];
int jd[10005];
bool can[10005];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    if (c <= 8) {
        memset(g, 0x3f, sizeof g);
        for (int i = 1; i <= n; i++) {
            cin >> l[i].sum;
            for (int j = 1; j <= l[i].sum; j++) {
                cin >> l[i].to[j] >> l[i].t[l[i].to[j]];
            }
            for (int j = 1; j <= l[i].sum; j++) {
                for (int k = j + 1; k <= l[i].sum; k++) {
                    int dist = l[i].t[l[i].to[j]] + l[i].t[l[i].to[k]];
                    g[l[i].to[j]][l[i].to[k]] = dist;
                    g[l[i].to[k]][l[i].to[j]] = dist;
                }
            }
        }
        for (int k = 1; k <= m; k++) {
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= m; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << g[x][y] + w[x] + w[y] << "\n";
        }
        return 0;
    }
}