#include <iostream>
using namespace std;
int c, t, n;
long long d, x[2000005];
int f[2000005];
long long g[2000005], sum[2000005], ans;
void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", x + i);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = i + 1, rt = i;
        f[i] = sum[i - 1] = 0;
        g[i] = sum[i] = 1;
        while (r <= n) {
            while (x[r] - x[l] > d)
                ++l;
            if (l == r) break;
            f[r] = f[l] + 1;
            while (rt + 1 < r && f[rt + 1] <= f[l])
                ++rt;
            g[r] = sum[rt] - sum[l - 1];
            sum[r] = sum[r - 1] + g[r];
            if (g[r] == 2) ++ans;
            ++r;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}