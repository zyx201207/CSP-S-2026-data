// tuxiaolai
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;

int c, n, k;

vector<int> adj[N];

namespace Solve1 {
    namespace Dsu {
        int fa[N], cnt;
        void init() {
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
            }
            cnt = n;
        }
        int find(const int u) {
            return u == fa[u] ? u : fa[u] = find(fa[u]);
        }
        void merge(int u, int v) {
            u = find(u), v = find(v);
            cnt -= u != v;
            fa[u] = v;
        }
    }
    int fa[N], dep[N];
    namespace Dis {
        void dfs(const int u, const int f) {
            cerr << u << '\n';
            fa[u] = f, dep[u] = dep[f] + 1;
            for (const int v: adj[u]) {
                if (v == f) continue;
                dfs(v, u);
            }
        }
        int dis(int u, int v) {
            int res = 0;
            while (u != v) {
                if (dep[u] > dep[v]) swap(u, v);
                v = fa[v], res++;
            }
            return res;
        }
    }
    int tmp[N];
    void solve() {
        Dis::dfs(1, 0);
        int res = 1e9;
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0, nw = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) tmp[++cnt] = j + 1;
            }
            if (cnt != k) continue;
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) {
                    int d = 1e9;
                    for (int k = 1; k <= cnt; k++) {
                        d = min(d, Dis::dis(j, tmp[k]));
                    }
                    nw = max(nw, d);
                }
            }
            res = min(res, nw);
        }
        cout << res << '\n';
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cerr << adj[i].size() << ' ';
    if (n <= 10) {
        Solve1::solve();
    }

}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> c >> T;
    while (T--) {
        solve();
    }

    return 0;
} // g++ hub.cpp -o hub -O2 -std=c++14 -Wall -Wextra -Wshadow -Wconversion -Wl,--stack=512000000