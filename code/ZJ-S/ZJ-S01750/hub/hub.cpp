/*
start at 17:01
finish at 18:09
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000100, M = 17000000, inf = 0x3f3f3f3f;
int ic, T, n, m;
vector<int> to[N];
int id(int x, int y) {
    return x * (m + 1) + y;
}
int f[M][2][3], sz[N];
int g[N][2][3];
inline void Max(int &x, int y) {
    if (x < y) x = y;
}
void dfs(int u, int fa, int mid) {
    for (int i = 0; i <= m; ++i) for (int j : {0, 1}) for (int k : {0, 1, 2}) f[id(u, i)][j][k] = -inf;
    sz[u] = 1, f[id(u, 0)][0][0] = -1, f[id(u, 1)][1][1] = mid;
    for (int v : to[u]) if (v != fa) {
        dfs(v, u, mid);
        for (int i = 0; i <= min(sz[u], m); ++i) for (int j : {0, 1}) for (int k : {0, 1, 2}) g[i][j][k] = f[id(u, i)][j][k], f[id(u, i)][j][k] = -inf;
        for (int i = 0; i <= min(sz[u], m); ++i) for (int j = 0; j <= min(sz[v], m - i); ++j) {
            for (int x : {0, 1, 2}) for (int y : {0, 1, 2}) {
                if (x + y <= 2) {
                    int p = g[i][0][x], q = max(f[id(v, j)][0][y], f[id(v, j)][1][y]) - 1;
                    if (p + q >= -1) Max(f[id(u, i + j)][0][x + y], max(p, q));
                    else Max(f[id(u, i + j)][0][x + y], min(p, q));
                    if (f[id(v, j)][0][y] >= -mid && g[i][1][x] == mid) f[id(u, i + j)][1][x + y] = mid;
                }
                if (x + y <= 3) {
                    if (g[i][1][x] == mid && f[id(v, j)][1][y] == mid) f[id(u, i + j)][1][x + y - 1] = mid;
                }
            }
        }
        sz[u] += sz[v];
    }
    return;
}
void solve() {
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) cin >> u >> v, to[u].emplace_back(v), to[v].emplace_back(u);
    if (ic == 13 || ic == 14) {
        int o = n / 2 + 2, l = 0, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = mid + 1, y = o - mid;
            int p = x + m / 2 - 1, q = y - (m + 1) / 2 + 1, nd = q - p - 1;
            int dis = (nd + 1) / 2 + 1;
            if (dis <= mid) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (m == 1) ans = o / 2;
        if (m != n) ans = max(ans, 1);
        else ans = 0;
        cout << ans << '\n';
    }
    else {
        int l = 0, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            dfs(1, 1, mid);
            bool flg = 0;
            for (int i = 0; i <= m; ++i) for (int x : {0, 1}) for (int y : {0, 1, 2}) if (f[id(1, i)][x][y] >= 0) flg = 1;
            if (flg) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    for (int i = 1; i <= n; ++i) to[i].clear();
    return;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> ic >> T;
    while (T--) solve();
    return 0;
}