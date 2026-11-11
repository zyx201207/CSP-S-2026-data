#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define sc if(DEBUG) cerr
const bool DEBUG = false;

const int N = 505, M = 5e5 + 5;
const ll inf = 1ll << 60;

int c, n, m, d, q, w[M], K[N];
ll dis[N][N];
vector<int> a[N], t[N];
vector<pair<int, int>> p[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i) {
        cin >> K[i];
        a[i].resize(K[i] + 1), t[i].resize(K[i] + 1);
        for(int j = 1; j <= K[i]; ++j) {
            cin >> a[i][j] >> t[i][j];
            p[a[i][j]].push_back({i, j});
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dis[i][j] = inf;
    for(int _ = 1; _ <= m; ++_)
        for(int i = 0; i < (int)p[_].size(); ++i)
            for(int j = 0; j < (int)p[_].size(); ++j) {
                pair<int, int> x = p[_][i], y = p[_][j];
                ll w = (i == j ? 0 : (ll)t[x.first][x.second] + t[y.first][y.second]);
                dis[x.first][y.first] = min(dis[x.first][y.first], w);
            }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) {
                if(dis[i][k] == inf || dis[k][j] == inf) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }

    while(q--) {
        int x, y;
        cin >> x >> y;

        ll res = inf;
        for(int i = 0; i < (int)p[x].size(); ++i)
            for(int j = 0; j < (int)p[y].size(); ++j) {
                pair<int, int> u = p[x][i], v = p[y][j]; // u != v
                res = min(res, dis[u.first][v.first] + t[u.first][u.second] + t[v.first][v.second] + w[x] + w[y]);
            }

        cout << res << "\n";
    }
    return 0;
}
