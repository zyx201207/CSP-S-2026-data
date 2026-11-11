#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1E6 + 5;
vector<int> E[N];
int dep[N];
int fa[N][25];

void dfs(int u, int fat) {
    dep[u] = dep[fat] + 1;
    fa[u][0] = fat;
    for (int i = 1; i < 25; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : E[u]) {
        if (v == fat) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 24; i >= 0; i--) {
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 24; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

vector<int> vised;
set<int> S;

void dfsfind(int u, int fat) {
    vised.push_back(u);
    for (int v : E[u]) {
        if (S.find(v) != S.end() && v != fat) {
            dfsfind(v, u);
        }
    }
}


void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) E[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 1e9;
    for (int ST = 0; ST < (1 << n); ST++) {
        if (__builtin_popcount(ST) != k) continue;
        S.clear();
        for (int i = 1; i <= n; i++) if (ST & (1 << (i - 1))) S.insert(i);
        bool flg = 0;
        vised.clear();
        dfsfind(*(S.begin()), 0);
        set<int> viss1;
        viss1.clear();
        for (int v : vised) viss1.insert(v);
        if (vised.size() == S.size()) flg = 1;
        if (!flg) {
            int fr = 0;
            for (int v : S) {
                if (viss1.find(v) == viss1.end()) {
                    fr = v;
                    break;
                }
            }
            vised.clear();
            dfsfind(fr, 0);
            set<int> viss2; viss2.clear();
            for (int v : vised) viss2.insert(v);
            flg = 1;
            for (int v : S) {
                if (viss1.find(v) == viss1.end() && viss2.find(v) == viss2.end()) flg = 0;
            }
        }
        if (!flg) continue;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int mn = 1e9;
            for (int v : S) {
                mn = min(mn, dist(v, i));
            }
            mx = max(mx, mn);
        }
        ans = min(ans, mx);
    }
    cout << ans << '\n';
}

signed main() {
    freopen("hub.in", "r", stdin);  
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
}