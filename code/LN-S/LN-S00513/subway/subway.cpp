#include <bits/stdc++.h>
using namespace std;
const long long  INF = 0x3f3f3f3f;
long long c, n, m, d, q;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    long long w[m + 5];
    long long a[n + 5][m + 5];
    long long t[n + 5][m + 5];
    long long G[m + 5][m + 5];
    for (long long i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (long long i = 1; i <= m; i++) {
        for (long long j = 1; j <= m; j++) {
            if (i == j) G[i][j] == 0;
            else G[i][j] = INF;
        }
    }
    for (long long i = 1; i <= n; i++) {
        long long K;
        cin >> K;
        for (long long j = 1; j <= K; j++) {
            cin >> a[i][j] >> t[i][j];
            for (long long k = 1; k <= j; k++) {
                G[a[i][j]][a[i][k]] = G[a[i][k]][a[i][j]] = min(G[a[i][j]][a[i][k]], t[i][j] + t[i][k]);
            }
        }
    }
    for (long long k = 1; k <= m; k++) {
        for (long long i = 1; i <= m; i++) {
            for (long long j = 1; j <= m; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    while (q--) {
        long long x, y;
        cin >> x >> y;
        cout << G[x][y] + w[x] + w[y] << endl;
    }
    return 0;
}
