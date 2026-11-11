#include <bits/stdc++.h>
#define int long long
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
const int N = 1e6 + 10;
int n, k, cas;
vector<int> e[N];
int pa[N];
bool vis[N];
int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
map<pii, bool> mp;
int fa[N], dep[N], siz[N], son[N], top[N];
void dfs1(int u) {
    siz[u] = 1;
    for (auto v : e[u]) {
        if (dep[v]) continue;
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v), siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int x) {
    top[u] = x;
    if (son[u]) dfs2(son[u], x);
    for (auto v : e[u])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}
int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[LCA(x, y)]; }
void solve1() {
    int ans = inf;
    for (int s = 0; s < (1 << n); s++) {
        if (__builtin_popcount(s) != k) continue;
        vector<int> v;
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= n; i++)
            if (s >> (i - 1) & 1) v.pb(i), vis[i] = 1;
        for (int i = 1; i <= n; i++) pa[i] = i;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++) {
                if (mp[{v[i], v[j]}]) {
                    int x = find(v[i]), y = find(v[j]);
                    if (x != y) pa[x] = y;
                }
            }
        set<int> st;
        for (int i = 0; i < v.size(); i++) st.insert(find(v[i]));
        if (st.size() == 2) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                if (vis[i]) continue;
                int mn = inf;
                for (int j = 1; j <= n; j++)
                    if (!vis[i] && vis[j])
                        mn = min(mn, dis(i, j));
                res = max(res, mn);
            }
            ans = min(ans, res);
        }
    }
    cout << ans << '\n';
}
void solve() {
    cin >> n >> k;
    mp.clear();
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        dep[i] = son[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        e[u].pb(v), e[v].pb(u);
        mp[{u, v}] = mp[{v, u}] = 1;
    }
    dep[1] = 1, dfs1(1), dfs2(1, 1);
    if (cas <= 3) solve1();
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> cas >> T;
    while (T--) solve();
    return 0;
}
