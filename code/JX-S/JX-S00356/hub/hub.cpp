#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

void tomax(int& x, int y) {
    x = max(x, y);
}
void tomin(int& x, int y) {
    x = min(x, y);
}

constexpr int MAXN = 1005;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int n, k;
vi G[MAXN];
int fa[MAXN];

int f[MAXN], height[MAXN];
int forb;
int lim;
int g[MAXN];
bool color[MAXN];

void dp(int u, int col) {
    // cerr << u << " " << col << " " << fa[u] << endl;
    color[u] = col;
    height[u] = 0;
    int flag = 0;
    for (int v : G[u]) if (v != fa[u] && v != forb) {
        // fa[v] = u;
        dp(v, col);
        f[u] += f[v];
        if (f[v]) flag = true;
        tomax(height[u], height[v]);
    }
    height[u]++;
    if (height[u] - 1 > lim) flag = 1;
    f[u] += flag;
}

void dp2(int u) {
    vi x;
    vi pre(sz(G[u])), suf(sz(G[u]));
    for (int v : G[u]) x.pb((v != fa[u] && v != forb) ? height[v] : 0);
    pre[0] = x[0];
    suf.back() = x.back();
    rep (i, 1, sz(G[u]) - 1) pre[i] = max(pre[i - 1], x[i]);
    per (i, sz(G[u]) - 2, 0) suf[i] = max(suf[i + 1], x[i]);
    int i = 0;
    for (int v : G[u]) {
        if (v != fa[u] && v != forb) {
            tomax(g[v], max({g[u], (i ? pre[i - 1] : 0ll), (i < sz(G[u]) - 1 ? suf[i + 1] : 0ll)}) + 1);
            dp2(v);
        }
        i++;
    }
}

bool check(int x) {
    lim = x;
    int mn = INF;
    rep (i, 2, n) {
        rep (i, 1, n) f[i] = 0, g[i] = 0, height[i] = 0;
        forb = i;
        dp(1, false);
        dp(i, true);
        // cerr << i << " : " << endl;
        dp2(1);
        dp2(i);
        // rep (j, 1, n) cerr << g[j] << " ";
        // cerr << endl;
        int x1 = INF, x2 = INF;
        rep (j, 1, n) if (g[j] - 1 <= x && color[j] == 0) {
            tomin(x1, f[j]);
        }
        rep (j, 1, n) if (g[j] - 1 <= x && color[j] == 1) {
            tomin(x2, f[j]);
        }
        // cerr << x1 << " " << x2 << endl;
        tomin(mn, x1 + x2);
    }
    return mn <= k;
}

void dfs(int u) {
    for (int v : G[u]) if (v != fa[u]) {
        fa[v] = u;
        // cerr << fa[v] << endl;
        dfs(v);
    }
}

void work() {
    cin >> n >> k;
    rep (i, 1, n) G[i].clear();
    rep (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1);
    // cerr << "!" << endl;
    int ans = -1;
    // cerr << check(100) << endl;
    for (int i = (1 << 20); i; i >>= 1) {
        if (!check(ans + i)) ans += i;
    }
    ans++;
    cout << ans << endl;
}

int c, t;

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t;
    while (t--) work();

    return 0;
}