#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, x, y, dis[505][505], w[500005], k[505];
vector<int> a[505], t[505];
vector<pair<int, int>> vec[500005];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 1e18;
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        int x, y;
        for (int j = 1; j <= k[i]; j++) {
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            vec[x].push_back({i, y});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            for (int k = j + 1; k < vec[i].size(); k++) {
                int v = vec[i][j].second + vec[i][k].second;
                dis[vec[i][j].first][vec[i][k].first] = min(dis[vec[i][j].first][vec[i][k].first], v);
                dis[vec[i][k].first][vec[i][j].first] = min(dis[vec[i][k].first][vec[i][j].first], v);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        cin >> x >> y;
        int ans = 1e18, sum = w[x] + w[y];
        for (int i = 0; i < vec[x].size(); i++) {
            for (int j = 0; j < vec[y].size(); j++) {
                int v = dis[vec[x][i].first][vec[y][j].first];
                ans = min(ans, v + vec[x][i].second + vec[y][j].second + sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}