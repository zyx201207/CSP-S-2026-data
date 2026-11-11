#include <bits/stdc++.h>
//#define int long long
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define fi first
#define se second
#define mod 998244353
#define Mod 1000000007
#define inf 1e18
using namespace std;
const int N = 5e5 + 10, M = 1.6e6 + 10;
int c, n, m, d, q, cnt;
LL a[N];
vector<pii> e[M];
inline void add(int u, int v, int w) {
    e[u].pb({v, w});
    e[v].pb({u, w});
}
struct node {
    int u, v, w;
    inline bool operator < (const node &it) const {
        return w < it.w;
    }
};
vector<node> edge;
int pa[M];
inline int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
inline void kruskal() {
    for (int i = 1; i <= cnt; i++) pa[i] = i;
    sort(edge.begin(), edge.end());
    int tot = 0;
    for (auto c : edge) {
        int u = c.u, v = c.v, w = c.w;
        int x = find(u), y = find(v);
        if (x != y) {
            add(u, v, w);
            pa[x] = y, tot++;
        }
        if (tot == cnt - 1) break;
    }
}
int fa[M], dep[M], siz[M], son[M], top[M];
LL dis[M];
inline void dfs1(int u) {
    siz[u] = 1;
    for (auto c : e[u]) {
        int v = c.fi, w = c.se;
        if (dep[v]) continue;
        dep[v] = dep[u] + 1, fa[v] = u;
        dis[v] = dis[u] + w;
        dfs1(v), siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
inline void dfs2(int u, int x) {
    top[u] = x;
    if (son[u]) dfs2(son[u], x);
    for (auto c : e[u]) {
        int v = c.fi;
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
    }
}
inline int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
/*inline int read() {
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar_unlocked();
    }
    return x * f;
}*/
inline void solve() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    cnt = n + m;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, t; cin >> x >> t;
            edge.pb({x, ++cnt, t});
            edge.pb({cnt, m + i, 0});
        }
    }
    kruskal();
    dep[1] = 1, dfs1(1);
    dfs2(1, 1);
    while (q--) {
        int u, v; cin >> u >> v;
        int l = LCA(u, v);
        LL ans = a[u] + a[v] + dis[u] + dis[v] - 2 * dis[l];
        cout << ans << '\n';
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
