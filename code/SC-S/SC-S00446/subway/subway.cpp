#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cctype>
#include <cmath>
#include <set>

#define int long long
#define FILENAME "subway"

const int MAXTRUN = 504;
const int MAXN = 510004;
const int MAXM = MAXN * 2;
const int MAXLOG = 21;

int c, n, m, d, q;
int w[MAXN];
struct Edge {
    int w, u, v;
    bool operator<(Edge const &rhs) const {
        return w < rhs.w;
    }
};
std::vector<Edge> es;
int par[MAXN];
int ucount = 0;
int head[MAXN], next[MAXM], weight[MAXM], point[MAXM], ecount = 2;

void add_sin(int u, int v, int w) {
    next[ecount] = head[u];
    head[u] = ecount;
    point[ecount] = v;
    weight[ecount] = w;
    ++ecount;
}
void add_dbl(int u, int v, int w) {
    add_sin(u, v, w);
    add_sin(v, u, w);
}

int findset(int u) {
    if (par[u] == u) return u;
    return par[u] = findset(par[u]);
}
bool mergeset(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u != v) {
        par[u] = v;
        return true;
    }
    return false;
}

int up[MAXN][MAXLOG], cost[MAXN][MAXLOG];
int dep[MAXN];
void dfs(int u, int p) {
    for (int e = head[u]; e; e = next[e]) {
        int v = point[e];
        if (v != p) {
            up[v][0] = u;
            cost[v][0] = weight[e];
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
}
void build_st() {
    for (int k = 1, pk = 0; k < MAXLOG; ++k, ++pk) {
        for (int u = 1; u <= ucount; ++u) {
            up[u][k] = up[up[u][pk]][pk];
            cost[u][k] = cost[u][pk] + cost[up[u][pk]][pk];
        }
    }
}
int lca(int u, int v) {
    int ans = 0;
    if (dep[u] < dep[v]) std::swap(u, v);
    int diff = dep[u] - dep[v], k = 0;
    while (diff) {
        if (diff & 1) {
            ans += cost[u][k];
            u = up[u][k];
        }
        ++k;
        diff >>= 1;
    }
    if (u == v) return ans;
    for (int k = MAXLOG - 1; k >= 0; --k) {
        if (up[u][k] != up[v][k]) {
            ans += cost[u][k] + cost[v][k];
            u = up[u][k];
            v = up[v][k];
        }
    }
    ans += cost[u][0] + cost[v][0];
    return ans;
}

signed main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) std::cin >> w[i];
    ucount = m;
    int k, u, v, t;
    for (int i = 0; i < n; ++i) {
        ++ucount;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            std::cin >> u >> t;
            es.push_back(Edge {t,u,ucount});
        }
    }
    for (u = 1; u <= ucount; ++u) {
        par[u] = u;
    }
    std::sort(es.begin(), es.end());
    for (auto e: es) {
        if (mergeset(e.u, e.v)) {
            add_dbl(e.u, e.v, e.w);
            // printf("%lld <-> %lld = %lld\n", e.u, e.v, e.w);
        }
    }
    dfs(1, 0);
    build_st();
    for (int Q = 0; Q < q; ++Q) {
        std::cin >> u >> v;
        t = lca(u, v) + w[u] + w[v];
        std::cout << t << '\n';
    }
    std::cout.flush();

    fclose(stdin);
    fclose(stdout);
    return 0;
}