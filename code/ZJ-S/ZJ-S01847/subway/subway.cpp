#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 10, M = 5e5 + 10;
int C, n, m, d, q, w[M];
vector<int> vec[M], t[M]; // 每个地铁站包含的线路集合 及 到对应线路的时间
int f[N][N]; // 线路i 到 线路j 的最短路
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1, k; i <= n; ++i) {
        cin >> k;
        for (int j = 1, x, tm; j <= k; ++j) {
            cin >> x >> tm;
            vec[x].push_back(i), t[x].push_back(tm);
        }
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        if (i != j) f[i][j] = 1e12;
    }
    for (int i = 1; i <= m; ++i) {
        // assert(vec[i].size() <= d); // 记得注释掉
        int len = vec[i].size();
        for (int j = 0; j < len; ++j) for (int k = 0; k < len; ++k) {
            if (j == k) continue;
            int u = vec[i][j], v = vec[i][k];
            f[u][v] = min(f[u][v], t[i][j] + t[i][k]);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (f[i][k] == 1e12) continue;
            for (int j = 1; j <= n; ++j) {
                if (f[k][j] == 1e12) continue;
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int u, v, ans = 1e16;
        cin >> u >> v;
        int lu = vec[u].size(), lv = vec[v].size();
        for (int i = 0; i < lu; ++i) for (int j = 0; j < lv; ++j) {
            int xi = vec[u][i], xj = vec[v][j];
            if (f[xi][xj] == 1e12) continue;
            ans = min(ans, w[u] + t[u][i] + f[xi][xj] + t[v][j] + w[v]);
        }
        cout << ans << '\n';
    }
}
// 15:45 过了所有大样例
// 是否应该相信 VS Code 的 Compare?