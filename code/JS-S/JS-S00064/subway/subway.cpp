#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
int c, n, m, d, q;
vector<pair<int, int>> e[500010];
int g[510][510];
int w[500010];
signed main() {
    freopen("subway.in", "a+", stdin);
    freopen("subway.out", "w+", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            e[a].push_back({i, t});
        }
    }

    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        vector<pair<int, int>> &ee = e[i];
        for (int j = 0; j < e[i].size(); j++) {
            for (int k = j + 1; k < e[i].size(); k++) {
                g[ee[j].first][ee[k].first] = min(g[ee[j].first][ee[k].first], ee[j].second + ee[k].second);
                g[ee[k].first][ee[j].first] = g[ee[j].first][ee[k].first];
            }
        }
    }
    // cout << g[1][2] << "\n";
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    while (q--) {
        int start, end;
        cin >> start >> end;

        int ans = inf;
        for (int i = 0; i < e[start].size(); i++) {
            for (int j = 0; j < e[end].size(); j++) {
                int u = e[start][i].first;
                int v = e[end][j].first;
                if (g[u][v] != inf)
                {
                    ans = min(e[start][i].second + e[end][j].second + g[u][v], ans);
                    // cout << u << " " << v << " " << g[u][v] << "\n";
                }                
            }
        }
        cout << ans + w[start] + w[end] << "\n";
    }

    
    return 0;
}