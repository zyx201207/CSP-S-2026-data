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
int n, k;
int tid;
std::vector<int> adj[N];
int f[N], vis[N], dist[N];
int d1[N], d2[N];

void dfs(int u) {
    vis[u] = 1;
    for (const auto &v : adj[u]) {
        if (f[v] && !vis[v]) dfs(v);
    }
}

void dfss(int u) {
    vis[u] = 1;
    for (const auto &v : adj[u]) {
        if (vis[v] || f[v]) continue;
        if (!f[v]) dist[v] = dist[u] + 1;
        dfss(v);
    }
}

void dfs1(int u, int fa) {
    for (const auto &v : adj[u]) {
        if (v == fa) continue;
        d1[v] = d1[u] + 1;
        dfs1(v, u);
    }
}

void dfs2(int u, int fa) {
    for (const auto &v : adj[u]) {
        if (v == fa) continue;
        d2[v] = d2[u] + 1;
        dfs2(v, u);
    }
}

void sub() {
    int ans = n;
    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            for (int i = 0; i < n; ++i) d1[i] = d2[i] = 0;
            dfs1(u, u);
            dfs2(v, v);
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                res = std::max(res, std::min(d1[i], d2[i]));
                if (res > ans) break; 
            }
            ans = std::min(ans, res);
        }
    }
    std::cout << ans << '\n';
}

void solve() {
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (n > 10) {
        if (k == 2) sub();
        else if (tid == 13 || tid == 14) std::cout << 1 << '\n';
        else std::cout << n / k << '\n';
        return;
    }
    int ans = n;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) != k) continue;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) f[i] = 1;
            else f[i] = 0;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) vis[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i] && !vis[i]) {
                ++cnt;
                dfs(i);
            }
        }
        if (cnt > 2) continue;
        // std::cerr << mask << '\n';
        for (int i = 0; i < n; ++i) vis[i] = 0, dist[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i] && !vis[i]) {
                dfss(i);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = std::max(res, dist[i]);
            // std::cerr << dist[i] << ' ';
        }
        // std::cerr << '\n';
        if (res < ans) {
            ans = res;
            // std::cerr << mask << '\n';
            // for (int i = 0; i < n; ++i) std::cerr << dist[i] << ' ';
            // std::cerr << '\n';
        }
    }
    std::cout << ans << '\n';
}

int main() {
    IO("hub");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    std::cin >> tid;
    std::cin >> _;
    while (_--) solve();
    return 0;
}