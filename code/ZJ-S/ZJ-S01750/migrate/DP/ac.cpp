#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000200, inf = 0x3f3f3f3f3f3f3f3f;
int ic, T, n, d;
int a[N], f[N], g[N];
void solve() {
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) f[j] = inf, g[j] = 0;
        f[i] = 0, g[i] = 1;
        for (int j = i; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (a[k] - a[j] > d) break;
                if (f[j] + 1 < f[k]) f[k] = f[j] + 1, g[k] = 0;
                if (f[j] + 1 == f[k]) g[k] = min(g[k] + g[j], 3ll);
            }
            if (g[j] == 2) ++ans;
        }
    }
    printf("%lld\n", ans);
}
signed main() {
    freopen("data.in", "r", stdin);
    freopen("ac.out", "w", stdout);
    scanf("%lld%lld", &ic, &T);
    while (T--) solve();
    return 0;
}