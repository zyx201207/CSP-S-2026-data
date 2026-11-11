#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[500005];
long long lin[500005][2];
long long f[1005][1005];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= m; i++) {
        scanf("%lld", &w[i]);
    }
    for(int i = 1; i <= n; i++) {
        long long k;
        scanf("%lld", &k);
        memset(lin, 0, sizeof(lin));
        for(int j = 1; j <= k; j++) {
            scanf("%lld %lld", &lin[j][0], &lin[j][1]);
            for(int x = 1; x < j; x++) {
                f[lin[x][0]][lin[j][0]] = f[lin[j][0]][lin[x][0]] = min(f[lin[x][0]][lin[j][0]], lin[x][1] + lin[j][1]);
            }
        }
    }
    for(int k = 1; k <= m; k++) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                f[i][j] = f[j][i] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while(q--) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        printf("%lld\n", w[x] + w[y] + f[x][y]);
    }
    return 0;
}
