#include <bits/stdc++.h>
#define int long long
#define elif else if
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int C, T;
    cin >> C >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        vector<int> x(n);
        for (auto& i : x) cin >> i;

        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
        for (int i = 1; i < n; ++i)
            g[i][i - 1] = g[i - 1][i] = ((x[i] - x[i - 1]) > d? INT_MAX : (x[i] - x[i - 1]));
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = min(g[i][j], (((g[i][k] + g[k][j]) > d && ((g[i][k] + g[k][j]) > 0))? INT_MAX : (g[i][k] + g[k][j])));

        int ans = 0;
        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int cnt = 0, dep = 0;
                queue<pair<int, int>> pq;
                pq.push({ u, 1 });
                vector<char> vis(n);
                vis[u] = 1;
                while (not pq.empty()) {
                    int i = pq.front().first;
                    int de = pq.front().second;
                    vis[i] = 1;
                    pq.pop();

                    if (dep != 0 and de != dep) break;

                    if (i == v) {
                        if (dep == 0) dep = de;
                        elif (de != dep) break;
                        cnt++;
                    }

                    for (int j = 0; j < n; ++j)
                        if (g[i][j] <= d and vis[j] == 0)
                            pq.push({ j, de + 1 }); 
                }
                if (cnt == 2) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
