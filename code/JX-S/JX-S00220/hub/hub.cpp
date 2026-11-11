#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, k, ans;
vector<int> G[N];
int fa[N][6], dep[N];
void dfs (int u) {
    for (int v : G[u]) {
        if (v == fa[u][0]) continue;
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        dfs (v);
    }
}
int Lca (int x, int y) {
    if (dep[x] < dep[y]) swap (x, y);
    for (int i = 5; i >= 0; i--) {
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 5; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
void solve () {
    ans = 1e9;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        G[i].clear ();
        dep[i] = 0;
        fa[i][0] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back (v);
        G[v].push_back (u);
    }
    dep[1] = 1;
    dfs (1);
    for (int j = 1; j <= 5; j++) {
        for (int i = 1; i <= n; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if ((mask >> (i - 1)) & 1) ++num;
        }
        if (num != k) continue;
        num = 0;
        for (int i = 1; i <= n; i++) {
            for (int v : G[i]) {
                if (v > i && ((mask >> (v - 1)) & 1)) num++;
            }
        }
        if (k - num > 2) continue;
        num = 0;
        for (int i = 1; i <= n; i++) {
            if (!((mask >> (i - 1)) & 1)) {
                int res = 1e9;
                for (int j = 1; j <= n; j++) {
                    if ((mask >> (j - 1)) & 1) {
                        res = min (res, dep[i] + dep[j] - 2 * dep[Lca (i, j)]);
                    }
                }
                num = max (num, res);
            }
        }
        ans = min (num, ans);
    }
    cout << ans << '\n';
}
int main () {
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) solve ();
    return 0;
}
