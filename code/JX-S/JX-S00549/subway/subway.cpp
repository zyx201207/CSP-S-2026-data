#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[500005], k[505], x[100005], y[100005];
vector<vector<int>> a, t;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    int a[n + 1][m + 1], t[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
    }
    if (m <= 500) {
        int g[m + 1][m + 1];
        memset(g, 0x3f, sizeof(g));
        for (int i = 1; i <= m; i++) {
            g[i][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k[i]; j++) {
                for (int l = j + 1; l <= k[i]; l++) {
                    int u = a[i][j], v = a[i][l];
                    int wei = t[i][j] + t[i][l];
                    g[u][v] = min(g[j][l], wei);
                    g[v][u] = min(g[l][j], wei);
                }
            }
        }

        //for (int j = 1; j <= m; j++) {
        //    for (int l = 1; l <= m; l++) {
        //        cout << (g[j][l] >= 1e9 ? -1ll : g[j][l]) << " ";
        //    }
        //    cout << "\n";
        //}

        for (int i = 1; i <= m; i++) {
            for (int u = 1; u <= m; u++) {
                for (int v = 1; v <= m; v++) {
                    if (g[i][u] + g[i][v] < g[u][v]) {
                        int wei = g[i][u] + g[i][v];
                        g[u][v] = wei;
                        g[v][u] = wei;
                    }
                }
            }
        }
        for (int i = 1; i <= q; i++) {
            cout << w[x[i]] + w[y[i]] + g[x[i]][y[i]] << "\n";
        }
    }
    return 0;
}












//16:50
//I don't remember how to write Floyd.
//I will AFO and learn whk.
