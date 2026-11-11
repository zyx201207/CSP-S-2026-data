// chennie ls bless me
// cubber ls bless me
// Oct31==Dec25?

#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <numeric>
#include <iomanip>
#include <queue>
#include <random>
#include <time.h>
using i64 = long long;
#define sz(x) (int)x.size()
#define IO(s) assert(freopen(s".in", "r", stdin)); assert(freopen(s".out", "w", stdout))
const int N = 1e6 + 10;
int c, n, m, d, q;
i64 w[N], fa[N], dep[N], dist[N];
std::vector<std::pair<int, i64>> adj[N];
int cnt_node;
int up[21][N];

int find(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

struct node {
    int u, v;
    i64 ww;

    bool operator<(const node &o) const {
        return ww < o.ww;
    }
};
std::vector<node> edge;

void dfs(int u, int par) {
    up[0][u] = par;
    for (int i = 1; i < 21; ++i) up[i][u] = up[i - 1][up[i - 1][u]];
    for (const auto &E : adj[u]) {
        int v = E.first;
        i64 ww = E.second;
        if (v == par) continue;
        dep[v] = dep[u] + ww;
        dist[v] = dist[u] + 1;
        dfs(v, u);
    }
}

int jump(int u, int d) {
    for (int i = 20; ~i; --i) {
        if ((d >> i) & 1) u = up[i][u];
    }
    return u;
}

int lca(int u, int v) {
    if (dist[u] < dist[v]) std::swap(u, v);
    u = jump(u, dist[u] - dist[v]);
    if (u == v) return u;
    for (int i = 20; ~i; --i) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

void solve() {
    std::cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) std::cin >> w[i];
    cnt_node = m;
    for (int i = 1; i <= n; ++i) {
        int k;
        std::cin >> k;
        for  (int j = 1; j <= k; ++j) {
            int a, t;
            std::cin >> a >> t;
            ++cnt_node;
            edge.push_back({a, cnt_node, t});
            if (j > 1) edge.push_back({cnt_node - 1, cnt_node, 0});
        }
    }
    // std::cerr << "sadfsadf\n";
    for (int i = 1; i <= cnt_node; ++i) fa[i] = i;
    std::sort(edge.begin(), edge.end());
    for (const auto ccc : edge) {
        int u = ccc.u;
        int v = ccc.v;
        i64 ww = ccc.ww;
        // std::cerr << u << ' ' << v << ' ' << ww << '\n';
        int fu = find(u);
        int fv = find(v);
        if (fu == fv) continue;
        // std::cerr << u << ' ' << v << ' ' << ww << '\n';
        fa[fu] = fv;
        adj[u].emplace_back(v, ww);
        adj[v].emplace_back(u, ww);
    }
    // std::cerr << "sadfsadf\n";
    // std::cerr << sz(edge) << ' ' << cnt_node << '\n';
    dfs(1, 0);
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << dep[u] + dep[v] - dep[lca(u, v)] * 2 + w[u] + w[v] << '\n';
    }
}

int main() {
    IO("subway");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_--) solve();
    return 0;
}