#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

namespace Mort1s {
    const int N = 1e6 + 5;
    const int inf = 1e9;
    int n, k, ans;
    int a[N], d[N];
    bool vis[N], flag[N];
    vector<int> g[N];
    int dep[N], anc[N][25];
    inline void init(int u, int fa) {
        dep[u] = dep[fa] + 1, anc[u][0] = fa;
        for (int i = 1; i <= 20; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
        for (int v : g[u]) {
            if (v == fa) continue;
            init(v, u);
        }
    }
    inline int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 20; i >= 0; i--) {
            if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
        }
        if (u == v) return u;
        for (int i = 20; i >= 0; i--) {
            if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
        }
        return anc[u][0];
    }
    inline int dis(int u, int v) {
        int l = lca(u, v);
        return dep[u] + dep[v] - 2 * dep[l];
    }
    inline void check(int u, int fa) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (v == fa || !flag[v]) continue;
            check(v, u);
        }
    }
    inline void dfs(int step) {
        if (step > k) {
            int cnt = 0;
            for (int i = 1; i <= k; i++) vis[a[i]] = 0;
            for (int i = 1; i <= k; i++) {
                if (!vis[a[i]]) {
                    cnt++;
                    if (cnt > 2) return;
                    check(a[i], 0);
                }
            }
            int res = 0;
            for (int i = 1; i <= n; i++) {
                if (flag[i]) {
                    d[i] = 0;
                } else {
                    d[i] = inf;
                    for (int j = 1; j <= k; j++) {
                       d[i] = min(d[i], dis(i, a[j]));
                    }
                }
                res = max(res, d[i]);
            }
            ans = min(ans, res);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!flag[i]) {
                flag[i] = 1;
                a[step] = i;
                dfs(step + 1);
                flag[i] = 0;
            }
        }
    }
    inline void solve() {
        ans = inf;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear(), flag[i] = 0;
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        init(1, 0);
        dfs(1);
        cout << ans << '\n';
    }
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    IOS;
    int c = 0, t = 1;
    cin >> c >> t;
    while (t--) Mort1s::solve();
    return 0;
}
/*
5:26 写完暴力
哦不，我怒了，只剩 1h 看 T2 了
*/