#include <bits/stdc++.h>

using namespace std;
using num = long long;

const num nn = 550;
num dis[nn][nn];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
    num c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<num> to_station(m + 1);
    vector<vector<pair<num, num>>> connected(m + 1);
    for (num i = 1; i <= m; ++i) {
        cin >> to_station[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    for (num i = 1; i <= n; ++i) {
        dis[i][i] = 0;
        num k;
        cin >> k;
        for (num j = 1; j <= k; ++j) {
            num sta, w;
            cin >> sta >> w;
            connected[sta].push_back({i, w});
        }
    }
    for (num i = 1; i <= m; ++i) {
        for (num j = 0; j < connected[i].size(); ++j) {
            num u = connected[i][j].first, w1 = connected[i][j].second;
            for (num k = j + 1; k < connected[i].size(); ++k) {
                num v = connected[i][k].first, w2 = connected[i][k].second;
                dis[u][v] = dis[v][u] = min(dis[u][v], w1 + w2);
            }
        }
    }
    for (num k = 1; k <= n; ++k) {
        for (num i = 1; i <= n; ++i) {
            for (num j = 1; j <= n; ++j) {
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (num i = 0; i < q; ++i) {
        num u, v;
        cin >> u >> v;
        num ans = 0x3f3f3f3f3f3f3f3f;
        for (num j = 0; j < connected[u].size(); ++j) {
            num u2 = connected[u][j].first, w1 = connected[u][j].second;
            for (num k = 0; k < connected[v].size(); ++k) {
                num v2 = connected[v][k].first, w2 = connected[v][k].second;
                ans = min(ans, dis[u2][v2] + w1 + w2);
            }
        }
        cout << ans + to_station[u] + to_station[v] << '\n';
    }
}