#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, w[N];
vector<pair<int, int>> g[N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    while (n--) {
        int k, a[m], t;
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            cin >> a[i] >> t;
            for (auto e : g[a[i]]) {
                int b = e.first, t2 = e.second;
                g[a[i]].push_back({b, t + t2});
                g[b].push_back({a[i], t + t2});
            }
            g[a[i]].push_back({a[i - 1], 0});
            g[a[i - 1]].push_back({a[i], 0});
        }
    }
    long long dis[m][m];
    memset(dis, 0x3f, sizeof(dis));
    for (int k = 1; k <= m; ++k) {
        dis[k][k] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] + dis[x][y] << '\n';
    }
    return 0;
}
