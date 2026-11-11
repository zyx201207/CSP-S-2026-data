/*
start at 15:11
finish at 15:22
*/
#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
const int N = 505, M = 500500;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int ic, n, m, d, q;
int a[M];
vector<pli> b[M];
ll f[N][N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &ic, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i) scanf("%d", a + i);
    for (int i = 1, s; i <= n; ++i) {
        scanf("%d", &s);
        for (int j = 1, x, y; j <= s; ++j) {
            scanf("%d%d", &x, &y);
            b[x].emplace_back(y, i);
        }
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) f[i][j] = (i == j ? 0 : inf);
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < b[i].size(); ++j) for (int k = j + 1; k < b[i].size(); ++k) {
            ll x = b[i][j].first, z = b[i][k].first;
            int y = b[i][j].second, w = b[i][k].second;
            f[y][w] = min(f[y][w], x + z), f[w][y] = min(f[w][y], x + z);
        }
    }
    for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int _ = 1, u, v; _ <= q; ++_) {
        scanf("%d%d", &u, &v);
        ll ans = inf;
        for (int i = 0; i < b[u].size(); ++i) for (int j = 0; j < b[v].size(); ++j) {
            ll x = b[u][i].first, z = b[v][j].first;
            int y = b[u][i].second, w = b[v][j].second;
            ans = min(ans, f[y][w] + x + z);
        }
        printf("%lld\n", ans + a[u] + a[v]);
    }
    return 0;
}