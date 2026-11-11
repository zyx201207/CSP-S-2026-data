#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> gr(n, vector<int>());
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, u--, v--, gr[u].push_back(v), gr[v].push_back(u);
    
        int ans = 114514;
    for (int x = 0; x < n; x++) {
        if (gr[x].size() == 1) continue;
        vector<int> dep(n, 0), len(n, 0), faf(n, -1);
        auto dfs = [&]
            (auto &&slf, int u, int fa) -> void {
                if (fa != -1) dep[u] = dep[fa] + 1;
                faf[u] = fa;
                for (int v : gr[u]) if (v != fa) slf(slf, v, u), len[u] = max(len[v] + 1, len[u]);
            };
        dfs(dfs, x, -1);
        vector<array<int, 2>> F = {{-1, -1}, {-1, -1}};
        for (int u : gr[x]) {
            F.push_back({len[u] + 1, u});
            sort(F.begin(), F.end(), greater<>());
            F.pop_back();
        }
        auto dfs2 = [&](auto &&slf, int u, int fa, int fr) -> void {
            if (fa == x) fr = u;
            if (u != x) {
                if (F[0][1] == fr)
                    ans = min(ans, max({dep[u] / 2 , len[u] , F[1][0]}));
                else
                    ans = min(ans, max({dep[u] / 2 , len[u] , F[0][0]}));
            }
            for (int v : gr[u]) if (v != fa) slf(slf, v, u, fr);
        };
        dfs2(dfs2, x, -1, -1);
    }
    cout << ans << "\n";
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    for (cin >> c >> t; t; t--) solve();
}