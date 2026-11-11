#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e+6 + 6;
int ovo, T, n, m, tot;
int dep[maxn], sz[maxn], wc[maxn], top[maxn], fa[maxn], h[maxn], fp[maxn], sp[maxn];
bool tag[maxn];
struct E {
    int to, nxt;
}e[maxn * 2];
inline void add(int x, int y) {
    e[++tot] = {y, h[x]};
    h[x] = tot;
}
inline void init() {
    for (int i = 1; i <= n; i++) {
        dep[i] = sz[i] = wc[i] = top[i] = fa[i] = h[i] = 0;
    }
    tot = 0;
}
inline void init_bcj() {
    for (int i = 1; i <= n; i++) {
        fp[i] = i;
        sp[i] = 1;
    }
}
int find(int x) {
    return fp[x] == x ? x : fp[x] = find(fp[x]);
}
inline void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (sp[x] < sp[y]) swap(x, y);
        fp[y] = x;
        sp[x] += sp[y];
    }
}
void dfs1(int p, int fat) {
    fa[p] = fat;
    sz[p] = 1;
    dep[p] = dep[fat] + 1;
    for (int o = h[p]; o; o = e[o].nxt) {
        int i = e[o].to;
        if (i != fat) {
            dfs1(i, p);
            sz[p] += sz[i];
            if (sz[i] > sz[wc[p]]) wc[p] = i;
        }
    }
}
void dfs2(int p, int tp) {
    top[p] = tp;
    if (wc[p]) {
        dfs2(wc[p], tp);
        for (int o = h[p]; o; o = e[o].nxt) {
            int i = e[o].to;
            if (i != fa[p] && i != wc[p]) dfs2(i, i);
        }
    }
}
inline int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
inline int dis(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
inline void GOGOGO() {
    cin >> n >> m;
    init();
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    int ans = n;
    for (int i = 1; i < (1ll << n); i++) {
        if (__builtin_popcountll(i) == m) {
            for (int j = 1; j <= n; j++) tag[j] = 0;
            init_bcj();
            for (int j = 1; j <= n; j++) {
                if ((i >> (j - 1)) & 1) tag[j] = 1;
            }
            // if (tag[2] == 1 && tag[4] == 1) cerr << "nkh" << '\n';
            for (int j = 1; j <= n; j++) {
                if (tag[j]) {
                    for (int o = h[j]; o; o = e[o].nxt) {
                        int k = e[o].to;
                        if (tag[k]) merge(j, k);
                    }
                }
            }
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (tag[j] && fp[j] == j) cnt++;
            }
            if (cnt <= 2) {
                int res = 0;
                for (int j = 1; j <= n; j++) {
                    if (!tag[j]) {
                        int sjy = n;
                        for (int k = 1; k <= n; k++) {
                            if (tag[k]) sjy = min(sjy, dis(j, k));
                        }
                        res = max(res, sjy);
                    }
                }
                ans = min(ans, res);
            }
        }
    }
    cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> ovo >> T;
    while (T--) GOGOGO();
    return 0;
}

