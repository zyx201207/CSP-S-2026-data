#include <bits/stdc++.h>
using namespace std;

template<class T>
void output(vector<T> &v) {
    cout << "(" << v.size() << "): [";
    for (T x : v) cout << x << ", ";
    cout << "]\n";
}

#define debug(v) cout << #v; output(v)

void solve() {
    using i64 = int64_t;
    i64 n, d, ts = 0;
    cin >> n >> d;
    vector<i64> x(n);
    vector<int> fa(n, n), dep(n + 1), siz(n + 1, 1), dfn(n + 1);
    for (i64 &i : x) cin >> i;
    if (d == 1)
        return cout << 0 << "\n", void();
    for (int i = 0, j = 0; i < n && j < n; i++) {
        while (j < n && x[j] - x[i] <= d) j++;
        j--, fa[i] = j;
        if (j == i) fa[i] = n;
    }

    auto code = [&](int x, int y, int z) {
        if (x == y && y == z) return 0;
        if (x == y && y == z + 1) return 1;
        if (x == y + 1 && y == z) return 2;
        if (x == y + 1 && y == z + 1) return 3;
    };

    vector<array<int, 4>> precalc(n, {0, 0, 0, 0});

    for (int i = n - 1; i >= 0; i--) {
        for (int j : {0, 1, 2, 3}) {
            int x, y, z;
            if (j == 0) x = y = z = i;
            if (j == 1) x = y = i, z = i - 1;
            if (j == 2) x = i, y = z = i - 1;
            if (j == 3) x = i, y = i - 1, z = i - 2;
            if (x < 0 || y < 0 || z < 0) continue;

            i64 ans = 0;

            if (fa[x] != n && y != -1 && fa[y] > x) ans += fa[y] - fa[z];

            x = fa[x], y = fa[y], z = fa[z];
            if (y <= x - 1) z = max(z, y), y = x - 1; 
            z = max(z, y - 1);
            if (x != n && y != n && z != n) ans += precalc[x][code(x, y, z)];
            precalc[i][j] = ans;
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x = i, y = -1, z = -1, xlst = i;
        while (x != n) {
            if (x != n && y - 1 > i && z != -1) {
                ans += precalc[x][code(x, y, z)];
                break;
            }
            if (fa[x] != n && y != -1 && fa[y] > x) ans += fa[y] - fa[max(z, i)];

            x = fa[x];
            if (y != -1) y = fa[y];
            if (z != -1) z = fa[z];
            if (x - 1 > i && y <= x - 1) z = max(z, y), y = x - 1; 
            if (y - 1 > i) z = max(z, y - 1);
        }
    }
    cout << ans << "\n";

    /*
    for (int i = n - 1; i >= 0; i--)
        dep[i] = dep[fa[i]] + 1;
    for (int i = 0; i < n; i++)
        siz[fa[i]] += siz[i];
    auto dfs = [&](auto &&slf, int u) -> void {
        dfn[u] = ts++;
        for (int v : g[u]) slf(slf, v);
    }; dfs(dfs, n);
    auto anc = [&](int v, int u) {
        return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
    };

    vector<int> L1(n, n), L2(n, n);
    for (int i = 0, j = 0; i + 1 < n; i++) {
        while (j <= n && !(anc(i, j) && anc(i + 1, j))) j++;
        L1[i] = j;
    }
    for (int i = 0, j = 0; i + 2 < n; i++) {
        while (j <= n && !(anc(i, j) && anc(i + 1, j) && anc(i + 2, j))) j++;
        L2[i] = j;
    }

    debug(fa);
    debug(dep);
    debug(siz);
    debug(dfn);
    debug(L1);
    debug(L2);

    i64 ans = 0;
    for (int x = 1; x < n; x++) if (L1[x - 1] != n)
        ans += (dep[L1[x - 1]]) * (siz[x] - 1);
    for (int x = 2; x < n; x++) if (siz[x] > 1 && L2[x - 1] != n)
        ans -= 2 * (dep[L2[x - 2]]) * (siz[x] - 2);
    cout << ans << "\n";
    */
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, t;
    for (cin >> c >> t; t; t--) solve();
}