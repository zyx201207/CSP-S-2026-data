#include <bits/stdc++.h>
#define Mem(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define eb emplace_back
using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
using i128 = __int128;
using namespace std;
constexpr int N = 2e6 + 15, mod = 998244353;
constexpr i64 inf = 1e18;

int n, k;
vector<int> g[N];
int st[N][30], dfn[N], tmp;
i64 dep[N];
int fa[N];
bool us[N], t[N];

inline int find(int x) {
    while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

inline void join(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if (f1 != f2) fa[f1] = f2;
}

inline int get (int u, int v) {
    return dfn[u] < dfn[v] ? u : v;
}

void dfs (int u, int fa) {
    dfn[u] = ++ tmp;
    st[dfn[u]][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

inline int LCA (int u, int v) {
    if (u == v) return u;
    int x = dfn[u], y = dfn[v];
    if (x > y) swap (x, y);
    int d = __lg (y - x);
    ++ x;
    return get (st[x][d], st[y - (1 << d) + 1][d]);
}

inline i64 Dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}

inline void solve () {
    scanf ("%d%d", &n, &k);
    tmp = 0;
    for (int i = 1; i <= n; ++ i) {
        dfn[i] = dep[i] = 0;
        g[i].clear();
        for (int j = 0; j <= 25; ++ j) st[i][j] = 0;
    }
    for (int i = 1; i < n; ++ i) {
        int u, v;
        scanf ("%d%d", &u, &v);
        g[u].eb(v), g[v].eb(u);
    }
    dfs(1, 0);
    for (int j = 1; j <= 21; ++ j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++ i) {
            st[i][j] = get(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
    int S = (1 << n) - 1;
    i64 ans = inf;
    for (int s = 1; s <= S; ++ s) {
        for (int i = 1; i <= n; ++ i) fa[i] = 0, us[i] = t[i] = 0;
        if (__builtin_popcount(s) != k) continue;
        vector<int> vec;
        for (int i = 1; i <= n; ++ i) {
            if((s >> i - 1) & 1) vec.eb(i), fa[i] = i, us[i] = 1;
        }
        for (int u : vec) {
            for (int v : g[u]) {
                if (us[v]) join(u, v);
            }
        }
        int cnt = 0;
        for (int u : vec) {
            if (!t[find(u)]) ++ cnt;
            t[find(u)] = 1; 
        }
        if (cnt > 2) continue;
        i64 res = 0;
        for (int i = 1; i <= n; ++ i) {
            i64 now = inf;
            if (!us[i]) for (int j : vec) now = min (now, Dis(i, j));
            else now = 0;
            res = max(res, now);
        }
        ans = min (ans, res);
    }
    printf ("%lld\n", ans);
}

#define filename "hub"

int main () {
#ifdef filename
    freopen (filename ".in", "r", stdin);
    freopen (filename ".out", "w", stdout);
#endif
    int c, T_T;
    scanf ("%d%d", &c, &T_T);
    while (T_T --) solve ();
    return 0;
}