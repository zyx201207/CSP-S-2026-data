#include <bits/stdc++.h>
using namespace std;

int w[500005];
vector<pair<int, int> > p[500005];
long long g[505][505];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> w[i];
    for (int i = 1, k; i <= n; i ++) {
        cin >> k;
        for (int j = 1, x, t; j <= k; j ++) {
            cin >> x >> t;
            p[x].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i != j) g[i][j] = 1000000000000000000;
        }
    }
    for (int i = 1; i <= m; i ++) {
        for (auto j : p[i]) {
            for (auto k : p[i]) {
                g[j.first][k.first] = min(g[j.first][k.first], (long long)j.second + k.second);
            }
        }
    }
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                g[i][j] = g[i][j] < g[i][k] + g[k][j] ? g[i][j] : g[i][k] + g[k][j];
            }
        }
    }
    while (q --) {
        int x, y;
        cin >> x >> y;
        long long res = LLONG_MAX;
        for (auto i : p[x]) {
            for (auto j : p[y]) {
                res = min(res, w[x] + i.second + g[i.first][j.first] + j.second + w[y]);
            }
        }
        cout << res << '\n';
    }
    cerr << clock() << '\n';
    return 0;
}