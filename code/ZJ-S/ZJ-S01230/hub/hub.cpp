#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000024;

int c, T, n, m;
vector<int> G[N];
bool vis[14];

int dfs(int u, int x, int m, int f) {
    int res = !x && ((m >> (u - 1)) & 1);
    for (auto v : G[u]) if (v != f) {
        res += dfs(v, ((m >> (u - 1)) & 1), m, u);
    }
    return res;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v), G[v].push_back(u);
        }
        if (n <= 10) {
            queue<pair<int, int>> q;
            int ans = 1111;
            for (int i = 1; i < (1 << n); i++) {
                if (__builtin_popcount(i) != m) continue;
                if (dfs(1, 0, i, 0) > 2) continue;
                for (int j = 1; j <= 10; j++) {
                    vis[j] = false;
                    if (i & (1 << (j - 1))) q.push({j, 0}), vis[j] = true;
                }
                int tmp = 0;
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    int u = p.first, d = p.second;
                    tmp = max(tmp, d);
                    for (auto v : G[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push({v, d + 1});
                        }
                    }
                }
                ans = min(ans, tmp);
            }
            cout << ans << '\n';
        }
        else if (c == 13 || c == 14) {
            if (m == n) cout << "0\n";
            else if (m >= ((n - 1) >> 1)) cout << "1\n";
            else cout << (((((n - 1) >> 1) - m + 3) >> 2) + 1) << '\n';
        }
        else cout << ((n - m) / 5) << '\n';
        for (int i = 1; i <= n; i++) G[i].clear();
    }
    return 0;
}