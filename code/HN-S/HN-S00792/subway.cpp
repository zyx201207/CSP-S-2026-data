#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5, M = 505;
const ll inf = 1e18;
int c, n, m, d, q;
ll w[N];
vector<pair<int, ll>> vec[N];
ll f[M][M];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> m >> n >> d >> q;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        int p; ll dis;
        for (int j = 1; j <= t; j++) {
            cin >> p >> dis;
            vec[p].emplace_back((pair<int, ll>){i, dis});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++)
            f[i][j] = i == j ? 0 : inf;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            for (int k = j + 1; k < vec[i].size(); k++) {
                int x = vec[i][j].first, y = vec[i][k].first;
                ll d = vec[i][j].second + vec[i][k].second;
                f[x][y] = min(f[x][y], d), f[y][x] = min(f[y][x], d);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++)
                f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
        }
    }
    while (q--) {
        int i, j;
        cin >> i >> j;
        ll ans = inf;
        for (auto x : vec[i]) {
            for (auto y : vec[j])
                ans = min(ans, x.second + y.second + f[x.first][y.first]);
        }
        cout << ans + w[i] + w[j] << '\n';
    }
    return 0;
}