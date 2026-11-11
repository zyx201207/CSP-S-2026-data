#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 5;
int n, k;
bool hs[N], vis[N];
vector<int> e[N];
void dfs(int x, int fa) {
    vis[x] = 1;
    for (int v : e[x]) {
        if (v != fa && hs[v]) dfs(v, x);
    }
}
int dfs2(int x, int fa) {
    if (vis[x]) return 0;
    int res = 1e9;
    for (int v : e[x]) {
        if (v != fa) {
            res = min(res, dfs2(v, x));
        }
    }
    return res + 1;
}
void solve() {
    int ans = 1e9;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i < 1 << n; i++) {
        int cnt = 0, x, now = 0;
        for (int j = 1; j <= n; j++) {
            if (i & 1 << j - 1) {
                hs[j] = 1; ++cnt;
                x = j;
            }
            else hs[j] = 0;
        }
        if (cnt != k) continue;
        fill(vis, vis + n + 1, 0);
        dfs(x, 0);
        for (int j = 1; j <= n; j++) {
            if (vis[j]) --cnt, hs[j] = 0;
            else if (hs[j]) x = j;
        }
        if (!cnt) continue;
        dfs(x, 0);
        for (int j = 1; j <= n; j++) {
            if (hs[j] && vis[j] == 0) cnt = 0;
        }
        if (!cnt) continue;
        for (int i = 1; i <= n; i++) {
            now = max(dfs2(i, 0), now);
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
}
int main () {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}