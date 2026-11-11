#include <bits/stdc++.h>
#define N 505
#define M 500005
#define inf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmax(T &x, T y) {return x < y && (x = y, true);}
template <typename T> inline bool ckmin(T &x, T y) {return y < x && (x = y, true);}
int cas, n, m, d, q, w[M]; ll dis[N][N]; basic_string<pii> g[M];
signed main()
{
    file(subway);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> cas >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++ i) cin >> w[i];
    for (int i = 1, k, u, t; i <= n; ++ i)
        for (cin >> k; k --;)
            cin >> u >> t, g[u].push_back({t, i});
    for (int i = 1; i <= n; ++ i) memset(dis[i] + 1, 0x3f, n << 3), dis[i][i] = 0;
    for (int u = 1, sz, i, j, x, y, z; u <= m; ++ u)
        for (sz = g[u].size(), i = 0; i < sz; ++ i)
            for (x = g[u][i].se, j = i + 1; j < sz; ++ j)
                y = g[u][j].se, z = g[u][i].fi + g[u][j].fi, ckmin(dis[x][y], (ll)z), ckmin(dis[y][x], (ll)z);
    for (int k = 1, i, j; k <= n; ++ k)
        for (i = 1; i <= n; ++ i)
            for (j = 1; j <= n; ++ j)
                ckmin(dis[i][j], dis[i][k] + dis[k][j]);
    for (int u, v, i, j; q --;)
    {
        cin >> u >> v; ll res = inf;
        for (auto [x, a] : g[u])
            for (auto [y, b] : g[v])
                ckmin(res, dis[a][b] + w[u] + w[v] + x + y);
        cout << res << '\n';
    }
    return 0;
}