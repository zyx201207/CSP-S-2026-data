#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], k[505];
int a[505][500005], t[505][500005];
int f[1005][1005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
        f[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= m; ++i)
        scanf("%d", w[i]);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; ++j)
        {
            scanf("%d%d", &a[i][j], &t[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {

        for (int j =1; j <= k[i]; ++j)
        {

            for (int l = 1;l <= k[i] && l != j; ++l)
            {
                f[j][l] = min(f[j][l], t[i][j] + t[i][l]);
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {

        for (int u = 1; u <= m; ++u)
            for (int v = 1; v <= m; ++v)
            {
                f[u][v] = min(f[u][v], f[u][i] + f[i][v]);
            }
    }
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", f[x][y] +w[x] + w[y]);
    }
    return 0;
}
