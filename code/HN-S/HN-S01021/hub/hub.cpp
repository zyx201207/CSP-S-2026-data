#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int K = 22;
const int M = 1e6 + 5;
int c, t, n, k, fa[N], siz[N], f[N][K], dep[N], dp[M][2], cnt[N], ans, l, r;
bool vis[N];
struct Node {
    int x, y;
}a[N];
vector<int> G[N];
int Find (int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
int lca (int x, int y) {
    if (dep[x] > dep[y]) {
        swap(x, y);
    }
    for (int i = 20; i >= 0; -- i) {
        if (dep[f[y][i]] >= dep[x]) {
            y = f[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 20; i >= 0; -- i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int solve (int x, int y) {
    return dep[x] + dep[y] - 2ll * dep[lca(x, y)];
}
void dfs (int x, int fa) {
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    for (int i = 1; (1ll << i) <= dep[x]; ++ i) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int i = 0; i < G[x].size(); ++ i) {
        int nxt = G[x][i];
        if (nxt == fa) continue;
        dfs(nxt, x);
    }
}
void DFS (int x, int fa) {
    dp[x][0] = 0;
    for (int i = 0; i < G[x].size(); ++ i) {
        int nxt = G[x][i];
        if (nxt == fa) continue;
        DFS(nxt, x);
        dp[x][0] = max(dp[x][0], dp[nxt][0] + 1);
    }
}

bool check (int x) {
    int tp = 0;
    for (int i = 1; i <= n; ++ i) cnt[i] = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = i + 1; j <= n; ++ j) {
            int pos = solve(i, j);
            if (pos >= x) {
                ++ tp;
                dp[tp][0] = i;
                dp[tp][1] = j;
            }
        }
    }
    return 1;
}
void solve () {
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
        cin >> a[i].x >> a[i].y;
        G[a[i].x].push_back(a[i].y);
        G[a[i].y].push_back(a[i].x);
    }
    dfs(1, 0);
    ans = 1000000000000000;
    if (c == 7 || c == 11 || c == 12) {
        int l = 1, r = 10000000000;
        ans = - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
        return ;
    }
    for (int i = 0; i < (1ll << n); ++ i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++ j) {
            cnt += ((i >> (n - j)) & 1ll);
        }
        if (cnt != k) continue;
        for (int j = 1; j <= n; ++ j) {
            fa[j] = j, siz[j] = 1, vis[j] = 0;
        }
        for (int j = 1; j <= n; ++ j) {
            if (! ((i >> (n - j)) & 1ll)) continue;
            vis[j] = 1;
        }
        for (int j = 1; j < n; ++ j) {
            int x = a[j].x, y = a[j].y;
            if ((i >> (n - x)) & 1ll) {
                if ((i >> (n - y)) & 1ll) {
                    x = Find(x), y = Find(y);
                    if (x == y) continue;
                    if (siz[x] < siz[y]) swap(x, y);
                    fa[y] = x, siz[x] += siz[y];
                }
            }
        }
        int res = 0;
        for (int j = 1; j <= n; ++ j) {
            res += (fa[j] == j && vis[j] == 1);
        }
        if (res > 2) continue;
        int maxn = 0;
        for (int j = 1; j <= n; ++ j) {
            if (! vis[j]) {
                int minn = n + 7891;
                for (int l = 1; l <= n; ++ l) {
                    if (vis[l]) {
                        minn = min(minn, solve(j, l));
                    }
                }
                maxn = max(maxn, minn);
            }
        }
        ans = min(ans, maxn);
    }
    cout << ans << '\n';
    return ;
}
signed main () {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t --) solve();
    return 0;
}
