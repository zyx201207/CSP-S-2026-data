#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 1e18;
auto run = [](auto f, auto ...args) { return f(f, args...); };

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    auto solve = []() {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> tr(n);
        for (int i = 0, u, v; i < n - 1; i++) {
            cin >> u >> v, u--, v--;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));
        for (int rt = 0; rt < n; rt++) {
            dist[rt][rt] = 0;
            run([&](auto dfs, int u, int fa) -> void {
                for (int v : tr[u]) {
                    if (v == fa) continue;
                    dist[rt][v] = dist[rt][u] + 1;
                    dfs(dfs, v, u);
                }
            }, rt, n);
        }

        vector<int> sz(n + 1), hgt(n + 1);
        vector<vector<int>> grandfa(n + 1, vector<int>(n));
        run([&](auto dfs, int u, int fa) -> void {
            sz[u] = 1;
            grandfa[u][0] = u;
            for (int i = 1; i < n; i++) grandfa[u][i] = grandfa[fa][i - 1];
            for (int v : tr[u]) {
                if (v == fa) continue;
                dfs(dfs, v, u);
                sz[u] += sz[v];
                hgt[u] = max(hgt[u], hgt[v]);
            }
            hgt[u]++;
        }, 0, n);

        int ans = inf;
        for (int cent1 = 0; cent1 < n; cent1++) {
            for (int cent2 = cent1 + 1; cent2 <= n; cent2++) {
                if (sz[cent1] + sz[cent2] < k) continue;

                auto check = [&](int x) {
                    bool f = 1;
                    vector<char> need(n + 1);
                    need[cent1] = need[cent2] = 1;
                    run([&](auto dfs, int u, int fa, bool under) -> void {
                        int tmp = min(dist[u][cent1], dist[u][cent2]);
                        if (under && tmp > x) need[grandfa[u][x]] = 1;
                        else f &= (tmp <= x);
                        for (int v : tr[u]) {
                            if (v == fa) continue;
                            dfs(dfs, v, u, under || v == cent1 || v == cent2);
                        }
                    }, 0, n, cent1 == 0);
                    int cnt = 0;
                    for (int i = 0; i < n; i++) cnt += need[i];
                    return cnt <= k && f;
                };
                    
                int l = 0, r = n;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (check(mid)) r = mid;
                    else l = mid + 1;
                }
                ans = min(ans, l);
            }
        }
        cout << ans << "\n";
    };

    int c, _;
    cin >> c >> _;
    while(_--) solve();
    return 0;
}