#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e2 + 7, M = 5e5 + 7;
int C, D, n, m, q, w[M], dis[N][N];
vector<pair<int, int>> v[M];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cin >> C >> n >> m >> D >> q;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1, k, x, y; i <= n; ++i) {
        cin >> k;
        while (k--) cin >> x >> y, v[x].emplace_back(i, y);
    }
    for (int i = 1; i <= m; ++i)
        for (auto u : v[i]) for (auto v : v[i])
            dis[u.first][v.first] = min(dis[u.first][v.first], u.second + v.second);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
        dis[i][j] = dis[j][i] = min(dis[i][j], dis[j][i]);
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int x, y; q--; ) {
        cin >> x >> y; int ans = 1e18;
        for (auto i : v[x]) for (auto j : v[y]) ans = min(ans, i.second + dis[i.first][j.first] + j.second);
        cout << w[x] + ans + w[y] << '\n';
    }
    return 0;
}