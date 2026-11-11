#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int dis[N][N];
bool vis[N];
vector <int> G[N];
int num (int x) {
    int cnt = 0;
    for (int i = 20; i >= 0; i--) if ((1 << i) & x) ++ cnt;
    return cnt;
}
void dfs (int u, int k) {
    if (vis[u]) return;
    vis[u] = true;
    for (auto v : G[u]) {
        if ((1 << v) & k) dfs (v, k);
    }
}
void dfs1 (int s, int u) {
    for (auto v : G[u]) {
        if (dis[s][v] > dis[s][u] + 1) {
            dis[s][v] = dis[s][u] + 1;
            dfs1 (s, v);
        }
    }
}
int main () {
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    int c, t; cin >> c >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            G[i].clear ();
            vis[i] = false;
        }
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            -- u, -- v;
            G[u].push_back (v), G[v].push_back (u);
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dis[i][j] = dis[j][i] = 100;
        for (int i = 0; i < n; i++) dis[i][i] = 0;
        for (int i = 0; i < n; i++) dfs1 (i, i);
        int tot = (1 << (n + 1));
        int res = 100;
        for (int i = 1; i <= tot; i++) {
            if (num (i) != k) continue;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (((1 << j) & i) && !vis[j]) {
                    dfs (j, i);
                    ++ cnt;
                }
            }
            if (cnt > 2) continue;
            int maxx = 0;
            for (int j = 0; j < n; j++) {
                int minn = 100;
                for (int k = 0; k < n; k++) {
                    if ((1 << k) & i) {
                        minn = min (minn, dis[j][k]);
                    }
                }
                maxx = max (maxx, minn);
            }
            res = min (maxx, res);
        }
        cout << res << "\n";
    }
    return 0;
}
