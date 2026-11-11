#include <bits/stdc++.h>
#define lt long long
using namespace std;

const int D = 30;
const int N = 505;
const int M = 5 * 1e5 + 10;

lt c, n, m, d, q, w[M];
lt a[N][M], t[N][M];
lt kt[N];
lt G[N][N], dp[N][N];
vector<lt> l[M];

inline lt read() {
    lt x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        lt k = read();
        kt[i] = k;
        for (int j = 1; j <= k; j++) {
            a[i][j] = read(), t[i][j] = read();
            l[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) G[i][j] = dp[i][j] = 1LL << 62;
    for (int i = 1; i <= m; i++) {
        for (auto j : l[i]) {
            for (auto k : l[i]) {
                if (j == k) {
                    G[i][j] = 0;
                    continue;
                }
                G[i][j] = min(G[i][j], t[j][i] + t[k][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--) {
        lt x = read(), y = read();
        lt ans = 1LL << 62;
        for (auto i : l[x]) {
            for (auto j : l[y]) {
                ans = min(ans, t[i][x] + dp[i][j] + t[j][y]);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}
