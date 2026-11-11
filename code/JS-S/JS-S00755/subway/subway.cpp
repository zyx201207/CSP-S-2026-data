// subway.cpp
#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, a, t, x, y;
int ps(int u, int v) {
    return u*n+v;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    int w[m+5], f[ps(m+5, n+5)][ps(m+5, n+5)];
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= ps(m+5, n+5); i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d%d", &a, &t);
            f[ps(a, i)][ps(0, i)] = f[ps(0, i)][ps(a, i)] = 0;
            f[ps(a, 0)][ps(a, i)] = f[ps(a, i)][ps(a, 0)] = t;
        }
    }
    for (int i = ps(0, 0); i <= ps(m, n); i++) for (int j = ps(0, 0); j <= ps(m, n); j++)
        for (int k = ps(0, 0); k <= ps(m, n); k++) f[j][i] = min(f[j][i], f[k][i]+f[j][k]);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", f[ps(x, 0)][ps(y, 0)]+w[x]+w[y]);
    }
    return 0;
}
