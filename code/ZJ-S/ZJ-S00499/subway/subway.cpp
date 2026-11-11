#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int maxn = 505, kMaxN = 5e+5 + 5, inf = 1e17;
int c, m, n, d, q;
int dis[maxn][maxn], a[kMaxN];
vector<pii> v[kMaxN];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int o;
        cin >> o;
        while (o--) {
            int x, y;
            cin >> x >> y;
            // cerr << "x: " << x << " o: " << o <<'\n';
            v[x].push_back({i, y});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            for (int k = j + 1; k < (int)v[i].size(); k++) {
                int x = v[i][j].first, y = v[i][k].first, z = v[i][j].second + v[i][k].second;
                dis[x][y] = dis[y][x] = min(dis[x][y], z);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = inf;
        for (int i = 0; i < (int)v[x].size(); i++) {
            for (int j = 0; j < (int)v[y].size(); j++) {
                ans = min(ans, dis[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second);
            }
        }
        ans += a[x] + a[y];
        cout << ans << '\n';
    }
    return 0;
}

