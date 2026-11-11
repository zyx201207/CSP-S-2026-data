#include <bits/stdc++.h>
using namespace std;

namespace baoli {
    const int N = 4e3 + 7;
    int n, k, p, q, mx, ans, c[N], f[N];
    vector<int> e[N];

    inline int ddfs(int u, int fa, int fu) {
        int dep = 0;
        for (int v : e[u]) if (v ^ fa && v ^ fu) dep = max(dep, ddfs(v, u, fu) + 1);
        return ++c[dep], dep;
    }
    inline void find(int u, int d, int fu) {
        if (d > mx) mx = d, p = u;
        for (int v : e[u]) if (v ^ f[u] && v ^ fu) f[v] = u, find(v, d + 1, fu);
    }
    inline int get(int u, int fa) {
        if (!u) return n + 1;
        f[u] = fa, mx = 0, find(u, 1, fa);
        q = p, mx = 0, f[q] = 0, find(q, 1, fa);
        mx >>= 1;
        while (mx--) p = f[p];
        return ddfs(p, fa, fa);
    }
    inline void dfs(int u, int fa) {
        for (int i = 0; i <= n; ++i) c[i] = 0;
        int d = min(get(u, fa), get(fa, u));
        for (int i = n; i > d; --i)
            if ((c[i] += c[i + 1]) < k) ans = min(ans, i);
            else break;
        for (int i = d; ~i; --i)
            if ((c[i] += c[i + 1]) <= k) ans = min(ans, i);
            else break;
        for (int v : e[u]) if (v ^ fa) dfs(v, u);
    }
    inline void solve() {
        cin >> n >> k, ans = 1e9;
        for (int i = 1; i <= n; ++i) e[i].clear();
        for (int i = 1, u, v; i < n; ++i) cin >> u >> v, e[u].emplace_back(v), e[v].emplace_back(u);
        dfs(1, 0), cout << ans << '\n';
    }
}
namespace randdd {
    const int N = 1e6 + 7;
    int TT, n, k, p, q, mx, ans, c[N], f[N], dd[N], fat[N], id[N];
    vector<int> e[N];

    inline int ddfs(int u, int fa, int fu) {
        int dep = 0;
        for (int v : e[u]) if (v ^ fa && v ^ fu) dep = max(dep, ddfs(v, u, fu) + 1);
        return ++c[dep], dep;
    }
    inline void find(int u, int d, int fu) {
        if (d > mx) mx = d, p = u;
        for (int v : e[u]) if (v ^ f[u] && v ^ fu) f[v] = u, find(v, d + 1, fu);
    }
    inline int get(int u, int fa) {
        if (!u) return n + 1;
        f[u] = fa, mx = 0, find(u, 1, fa);
        q = p, mx = 0, f[q] = 0, find(q, 1, fa);
        mx >>= 1;
        while (mx--) p = f[p];
        return ddfs(p, fa, fa);
    }
    inline void calc(int u, int fa) {
        for (int i = 0; i <= n; ++i) c[i] = 0;
        int d = min(get(u, fa), get(fa, u));
        for (int i = n; i > d; --i)
            if ((c[i] += c[i + 1]) < k) ans = min(ans, i);
            else break;
        for (int i = d; ~i; --i)
            if ((c[i] += c[i + 1]) <= k) ans = min(ans, i);
            else break;
    }
    inline void dddfs(int u, int fa) {
        dd[u] = dd[fa] + 1, fat[u] = fa;
        for (int v : e[u]) if (v ^ fa) dddfs(v, u);
    }
    inline void solve() {
        int clk = clock();
        cin >> n >> k, ans = 1e9;
        for (int i = 1; i <= n; ++i) e[i].clear();
        for (int i = 1, u, v; i < n; ++i) cin >> u >> v, e[u].emplace_back(v), e[v].emplace_back(u);
        mx = 0, find(1, 1, 0);
        q = p, mx = 0, f[q] = 0, find(q, 1, 0);
        mx >>= 1;
        while (mx--) p = f[p];
        dddfs(p, 0);
        mt19937 rnd(time(0));
        iota(id, id + n + 1, 0);
        sort(id + 1, id + n + 1, [](int i, int j) { return dd[i] < dd[j]; });
        for (int i = 1; i <= n; ++i) {
            if (clock() - clk > TT) break;
            if (dd[id[i]] > 1) calc(id[i], fat[id[i]]);
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int c, T; cin >> c >> T;
    if (c <= 10) while (T--) baoli::solve();
    else {
        randdd::TT = 2750000 / T;
        while (T--) randdd::solve();
    }
    return 0;
}