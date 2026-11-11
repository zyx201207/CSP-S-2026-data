#include <bits/stdc++.h>
using namespace std;

ifstream inf("subway.in");
ofstream ouf("subway.out");

#define vec vector
using i64 = long long;

const i64 inf64 = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios::sync_with_stdio(false), inf.tie(nullptr);

    int c, n, m, d, q;
    inf >> c >> n >> m >> d >> q;
    vec<i64> w(m + 1);
    for (int i = 1; i <= m; ++i) inf >> w[i];
    vec<int> id1(n + 1), id2(m + 1);
    vec<vec<pair<int, i64>>> bak(m + 1);
    int tot = 0;
    for (int i = 1; i <= n; ++i) id1[i] = ++tot;
    for (int i = 1; i <= m; ++i) id2[i] = ++tot;
    vec<vec<pair<int, i64>>> adj(tot + 1);
    auto add = [&](int u, int v, i64 w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    };
    for (int i = 1; i <= n; ++i) {
        int k;
        inf >> k;
        for (int j = 1; j <= k; ++j) {
            int a; i64 t;
            inf >> a >> t;
            bak[a].emplace_back(i, t);
            add(id2[a], id1[i], t);
        }
    }

    vec<vec<i64>> res(n + 1, vec<i64>(n + 1, inf64));
    for (int i = 1; i <= n; ++i) res[i][i] = 0;
    for (int i = 1; i <= m; ++i)
        for (auto [u, t1] : bak[i])
            for (auto [v, t2] : bak[i])
                res[u][v] = min(res[u][v], t1 + t2);
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);

    for (int cas = 1; cas <= q; ++cas) {
        int x, y;
        inf >> x >> y;
        i64 ans = inf64;
        for (auto [u, t1] : bak[x])
            for (auto [v, t2] : bak[y])
                ans = min(ans, w[x] + w[y] + t1 + t2 + res[u][v]);
        ouf << ans << "\n";
    }

    ouf.flush();
    return 0;
}