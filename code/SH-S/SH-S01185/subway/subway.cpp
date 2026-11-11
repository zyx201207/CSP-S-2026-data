#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 510, M = 5e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
int c, n, m, d, q, w[M];
struct to { int id; ll t; };
vector<to> g[M];
ll e[N][N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1, a, t; j <= k; j++)
            cin >> a >> t, g[a].push_back((to){.id = i, .t = t});
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) if (i != j) e[i][j] = inf;
    for (int i = 1; i <= m; i++) {
        assert(g[i].size() <= d);
        for (int j = 0; j < g[i].size(); j++)
            for (int k = j + 1; k < g[i].size(); k++)
                e[g[i][j].id][g[i][k].id] = e[g[i][k].id][g[i][j].id] = min(e[g[i][j].id][g[i][k].id], g[i][j].t + g[i][k].t);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
    while (q--) {
        int x, y; cin >> x >> y;
        ll dis = inf;
        for (to t1: g[x]) for (to t2: g[y])
            dis = min(dis, t1.t + e[t1.id][t2.id] + t2.t);
        cout << w[x] + dis + w[y] << '\n';
    }
    return 0;
}