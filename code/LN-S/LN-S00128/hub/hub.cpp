#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 1e6 + 5;

int dep[N], siz[N], son[N], p[N], dis[N];
std::vector < int > adj[N];
void dfs1(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    siz[u] = 1; p[u] = fa;
    for (int v : adj[u]) {
        if (v != fa) {
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
    }
}
int tp[N];
void dfs2(int u, int fa)
{
    tp[u] = fa;
    if (son[u]) dfs2(son[u], fa);
    for (int v : adj[u]) {
        if (v != p[u] && v != son[u]) {
            dfs2(v, v);
        }
    }
}
int lca(int x, int y)
{
    while (tp[x] != tp[y]) {
        if (dep[tp[x]] < dep[tp[y]]) std::swap(x, y);
        x = p[tp[x]];
    }
    if (dep[x] < dep[y]) return x;
    return y;
}
bool vis[N];
void dfs3(int u, int fa, int i)
{
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v != fa)
        {
            if (i >> (v - 1) & 1) {
                dfs3(v, u, i);
            }
        }
    }
}

int dist(int x, int y)
{
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void solve1()
{
    int n, k; std::cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    int ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) != k) continue;
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int j = 1; j <= n; j++) if (i >> (j - 1) & 1) {
            dfs3(j, 0, i); break;
        }
        for (int j = 1; j <= n; j++) if ((i >> (j - 1) & 1) && !vis[j]) {
            dfs3(j, 0, i); break;
        }
        bool f = 0;
        for (int j = 1; j <= n; j++) if ((i >> (j - 1) & 1) && !vis[j]) { f = 1; break; }
        
        if (!f)
        {
            for (int i = 1; i <= n; i++) dis[i] = 1e9;
            int res = 0;
            for (int j = 1; j <= n; j++) {
                if (i >> (j - 1) & 1) {
                    for (int k = 1; k <= n; k++) {
                        dis[k] = std::min(dis[k], dep[j] + dep[k] - 2 * dep[lca(j, k)]);
                    }
                }
            }
            for (int i = 1; i <= n; i++) res = std::max(res, dis[i]);
            ans = std::min(ans, res);
            // if (ans == 1) {
            //     std::cout << std::bin(i) << std::endl;
            //     return;
            // }
        }
    }
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; i++) {
        dep[i] = siz[i] = son[i] = p[i] = 0;
        adj[i].clear();
    }
}
void solve2()
{
    int n, k; std::cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1e9;
    dfs1(1, 0);
    int x = 1, y = 1;
    for (int i = 2; i <= n; i++) if (dep[i] > dep[x]) x = i;
    dfs1(x, 0);
    for (int i = 1; i <= n; i++) if (dep[i] > dep[y]) y = i;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans = std::max(ans, std::min(dist(k, x), dist(k, y)));
            }
        }
    }
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; i++) {
        dep[i] = siz[i] = son[i] = p[i] = 0;
        adj[i].clear();
    }
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t; std::cin >> c >> t;
    while (t--) {
        if (c <= 3) solve1();
        else if (c == 7 || c == 11 || c == 12) solve2();
    }
}