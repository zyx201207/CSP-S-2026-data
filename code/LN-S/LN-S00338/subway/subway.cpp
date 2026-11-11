#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[510000];
int a[500][510000], k[510000], t[500][510000];
int z[500][500];

int main () {
   freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1 ; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++){
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
            scanf("%d%d", &a[i][j], &t[i][j]);
    }
   for (int i = 1; i <= q; i++){
        int x, y;
        long long ans = 0;
        scanf("%d%d", &x, &y);
        ans += w[x];
        ans += t[x][i];
        cout << ans;
    }
}
