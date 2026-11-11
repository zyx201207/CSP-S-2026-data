#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 2000010, M = 5010;

int c, T, n;
LL d, a[N];
int f[M][M], g[M][M];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    scanf("%d%d", &c, &T);
    while (T -- )
    {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);

        if (c == 11 || c == 12)
        {
            LL res = 0;
            for (int i = 1; i < n; i ++ )
            {
                LL step = d / (a[2] - a[1]);
                if (step && i > step && (i + 1) % step == 0 && i < step * 2) res += n - i;
            }
            printf("%lld\n", res);
        }
        else
        {
            for (int i = 1; i <= n; i ++ )
                for (int j = i; j <= n; j ++ ) f[i][j] = n, g[i][j] = 0;
            for (int i = 1; i <= n; i ++ ) f[i][i] = 0, g[i][i] = 1;

            for (int len = 1; len < n; len ++ )
                for (int l = 1; l <= n - len; l ++ )
                {
                    int r = l + len;
                    for (int k = l + 1; k <= r; k ++ )
                    {
                        if (a[k] - a[l] > d) break;
                        if (f[l][r] == f[k][r] + 1) g[l][r] = min(3, g[l][r] + g[k][r]);
                        else if (f[l][r] > f[k][r] + 1)
                        {
                            g[l][r] = g[k][r];
                            f[l][r] = f[k][r] + 1;
                        }
                    }
                }
            int res = 0;
            for (int i = 1; i <= n; i ++ )
                for (int j = i + 1; j <= n; j ++ )
                    if (g[i][j] == 2) res ++ ;
            printf("%d\n", res);
        }
    }

    return 0;
}
