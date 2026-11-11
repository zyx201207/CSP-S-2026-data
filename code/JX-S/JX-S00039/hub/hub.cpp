#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 5;

vector<int> g[N];
bool vis[N], a[N];

void dfs (int u, int fa = 0) {
    if (!a[u]) return;
    vis[u] = true;
    for (int v : g[u]) {
        if (v != fa) dfs(v, u);
    }
}

int dfs1 (int u, int fa = 0, int dep = 0) {
    if (a[u]) return dep;
    int mn = 1e9;
    for (int v : g[u]) {
        if (v != fa) {
            mn = min(mn, dfs1(v, u, dep + 1));
        }
    }
    return mn;
}

int main () {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        if (c <= 6) {
            int ans = 1e9;
            for (int i = 1; i < 1 << n; i++) {
                if (__builtin_popcount(i) != m) continue;
                for (int j = 1; j <= n; j++) {
                    a[j] = i >> j - 1 & 1;
                }
                int cnt = 0;
                memset(vis + 1, 0, n);
                for (int j = 1; j <= n; j++) {
                    if (a[j] && !vis[j]) {
                        dfs(j); cnt++;
                    }
                }
                if (cnt > 2) continue;
                int mx = 0;
                for (int j = 1; j <= n; j++) {
                    mx = max(mx, dfs1(j));
                }
                ans = min(ans, mx);
            }
            cout << ans << '\n';
        } else {
            if (n == m) cout << "0\n";
            else cout << max(0, (n / 2 + 2 - m + 3) / 4 + 1) << '\n';
        }
        for (int i = 1; i <= n; i++) g[i].clear();
    }
    return 0;
}

// ming yun yi ran zhu ding
// nu li jie zai dang jin
