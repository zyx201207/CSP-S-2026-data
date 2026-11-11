#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 510, M = 5e5 + 10;

int tp, n, m, d, q, w[M];
ll f[N][N];
vector<pii> p[M];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> tp >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, a, t; j <= k; j++) {
            cin >> a >> t;
            p[a].push_back({i, t});
        }
        fill(f[i] + 1, f[i] + n + 1, 1e18), f[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < p[i].size(); j++) {
            for (int k = j + 1; k < p[i].size(); k++) {
                int id1 = p[i][j].first, w1 = p[i][j].second;
                int id2 = p[i][k].first, w2 = p[i][k].second;
                f[id1][id2] = min(f[id1][id2], 0ll + w1 + w2);
                f[id2][id1] = min(f[id2][id1], 0ll + w1 + w2);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int x, y; cin >> x >> y;
        ll ans = 3e18;
        for (int i = 0; i < p[x].size(); i++) {
            for (int j = 0; j < p[y].size(); j++) {
                int id1 = p[x][i].first, w1 = p[x][i].second;
                int id2 = p[y][j].first, w2 = p[y][j].second;
                ans = min(ans, w1 + w2 + f[id1][id2]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
