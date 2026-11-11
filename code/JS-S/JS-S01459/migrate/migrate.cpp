#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
typedef long long LL;
int n, d;
int x[N];
int f[N][N];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int C, T;
    scanf("%d%d", &C, &T);
    while(T--) {
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        memset(f, 0, sizeof f);
        for(int i = 1; i < n; i++)
            if(x[i + 1] - x[i] <= d) f[i][i + 1] = 1;
        LL ans = 0;
        for(int len = 3; len <= n; len++)
            for(int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                f[l][r] = (x[r] - x[l] <= d ? 1 : 0);
                for(int k = l + 1; k < r; k++) {
                    f[l][r] += f[l][k] * f[k][r];
                    if(f[l][r] > 2) {
                        f[l][r] = 3;
                        break;
                    }
                }
                if(f[l][r] == 2) ans++;
            }
        printf("%lld\n", ans - 1);
    }
    return 0;
}
