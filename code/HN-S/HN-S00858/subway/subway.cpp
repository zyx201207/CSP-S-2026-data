#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 500, M = 5e5 + 10;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int w[M];
vector<pair<int, int>> g[M];
ll dis[N][N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int to, w;
            cin >> to >> w;
            g[to].push_back({i, w});
        }
    }

    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;

    for (int i = 1; i <= m; ++i) {
        for (auto e1 : g[i]) {
            int x = e1.first, w1 = e1.second;
            for (auto e2 : g[i]) {
                int y = e2.first, w2 = e2.second;
                if (x == y) continue;
                dis[x][y] = min(dis[x][y], static_cast<ll>(w1) + w2);
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    
    while (q--) {
        int x, y;
        cin >> x >> y;

        ll ans = INF;
        for (auto e1 : g[x]) {
            int to1 = e1.first, w1 = e1.second;
            for (auto e2 : g[y]) {
                int to2 = e2.first, w2 = e2.second;
                ans = min(ans, dis[to1][to2] + w1 + w2);
            }
        }

        cout << ans + w[x] + w[y] << '\n';
    }
}