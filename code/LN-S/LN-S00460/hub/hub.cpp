#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, t, n, k, fa[N][22], dep[N], fd[N], ton[N];
bool cur[N];
vector<int> g[N];
void init() {
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    return;
}
void dfs(int u, int f) {
    fa[u][0] = f, dep[u] = dep[f] + 1;
    for (int v : g[u]) {
        if (v == f)
            continue;
        dfs(v, u);
    }
    return;
}
inline int ppc(int x) {
    int tmp = x, cnt = 0;
    while (tmp) {
        if (tmp & 1)
            cnt++;
        tmp >>= 1;
    }
    return cnt;
}
void init2() {
    for (int i = 1; i <= n; i++)
        fd[i] = i, cur[i] = false, ton[i] = 0;
    return;
}
inline int find(int u) {
    if (fd[u] == u)
        return u;
    return fd[u] = find(fd[u]);
}
inline bool check(int st) {
    if (ppc(st) != k)
        return false;
    init2();
    for (int i = 1; i <= n; i++)
        cur[i] = (st & (1 << (i - 1)));
    for (int i = 1; i <= n; i++) {
        if (!cur[i])
            continue;
        for (int v : g[i]) {
            if (!cur[v])
                continue;
            int fu = find(i), fv = find(v);
            if (fu != fv)
                fd[fu] = fv;
        }
    }
    for (int i = 1; i <= n; i++)
        ton[find(i)]++;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += (ton[i] > 0 && cur[i]);
    return res <= 2;
}
inline int lca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--)
        if (dep[fa[v][i]] >= dep[u])
            v = fa[v][i];
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
inline int getd(int u, int v) {
    int anc = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[anc];
}
inline void after() {
    for (int i = 1; i <= n; i++)
        g[i].clear(), dep[i] = 0, fa[i][0] = 0;
    return;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(1, 0);
        init();
        int ans = 0x3f3f3f3f;
        for (int st = 0; st <= (1 << n) - 1; st++) {
            if (!check(st))
                continue;
            int mx = -1;
            for (int i = 1; i <= n; i++) {
                if (cur[i]) {
                    mx = max(mx, 0);
                    continue;
                }
                int mi = 0x3f3f3f3f;
                for (int j = 1; j <= n; j++) {
                    if (!cur[j])
                        continue;
                    mi = min(mi, getd(i, j));
                }
                mx = max(mx, mi);
            }
            ans = min(ans, mx);
        }
        printf("%d\n", ans);
        after();
    }
    return 0;
}
// g++ hub.cpp -o hub