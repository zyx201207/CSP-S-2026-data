#include <bits/stdc++.h>
using namespace std;
const int N = 15;
vector<int> g[N];
bool vis[N], need[N];
void dfs(int u, int fa) {
    if (vis[u]) return ;
    vis[u] = true;
    for (auto v : g[u]) {
        if (v == fa) continue ;
        if (! need[v]) continue ;
        dfs(v, u);
    }
}
int f[N][N];
void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        g[i].clear();
        for (int j = 1; j <= n; j ++) if (i != j) f[i][j] = 1e6;
    }
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        f[u][v] = f[v][u] = 1;
    }
    for (int k = 1; k <= n; k ++) {
        for (int u = 1; u <= n; u ++) {
            for (int v = 1; v <= n; v ++) {
                if (f[u][k] < 1e6 and f[k][v] < 1e6) f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
            }
        }
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << n); mask ++) {
        int cnt = 0;
        vector<int> v;
        for (int i = 1; i <= n; i ++) {
            need[i] = 0;
            if ((mask >> (i-1)) & 1) cnt ++, v.push_back(i), need[i] = true;
            vis[i] = 0;
        }
        if (cnt != k) continue ;
        int nnn = 0;
        for (auto x : v) {
            if (!vis[x]) {
                nnn ++, dfs(x, 0);
            }
        }
        if (nnn > 2) continue ;
        int s = 0;
        for (int i = 1; i <= n; i ++) {
            int mi = 1e9;
            for (auto x : v) {
                mi = min(mi, f[x][i]);
            }
            s = max(s, mi);
        }
        ans = min(ans, s);
    }
    cout << ans << endl;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t; cin >> c >> t;
    while (t --) solve();
    return 0;
}
