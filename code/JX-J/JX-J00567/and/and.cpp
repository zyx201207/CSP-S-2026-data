#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2005;

int n, m, ans;
int a[N];
int f[N][N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) f[1][i] = a[i];
    for (int i = 2; i <= m; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][k] & a[j]);
            }
        }
    }

    for (int i = m; i <= n; i++) ans = max(ans, f[m][i]);
    printf("%d", ans);

    return 0;
}
