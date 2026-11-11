#include<bits/stdc++.h>
#define int long long

const int maxm = 1e6+5, inf = 1e18;
int w[maxm];
int dis[505][505];
int p[maxm][25], t[maxm][25], tp[maxm];

signed main() {
    freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
    std::cin.tie(0), std::cout.tie(0), std::ios::sync_with_stdio(0);
    int c, n, m, d, q; std::cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        std::cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k; std::cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a, tt; std::cin >> a >> tt;
            tp[a]++;
            p[a][tp[a]] = i, t[a][tp[a]] = tt;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dis[i][j] = inf;
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= tp[i]; ++j) {
            for (int k = 1; k <= tp[i]; ++k) {
                dis[p[i][j]][p[i][k]] 
                    = std::min(dis[p[i][j]][p[i][k]], t[i][j] + t[i][k]);
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        int x, y; std::cin >> x >> y;
        int xym = inf;
        for (int j = 1; j <= tp[x]; ++j) {
            for (int k = 1; k <= tp[y]; ++k) {
                xym = std::min(xym, dis[p[x][j]][p[y][k]] + t[x][j] + t[y][k]);
            }
        }
        xym += w[x] + w[y];
        std::cout << xym <<"\n";
    }
}