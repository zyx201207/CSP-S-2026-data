#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e6 + 10;
typedef long long LL;

int n;
LL m;
LL a[N];
LL f[N];
int g[N], q[N];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int tmp, T;
    scanf("%d%d", &tmp, &T);
    while (T -- )
    {
        scanf("%d%lld", &n, &m);
        for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);

        int res = 0;
        for (int k = 1; k <= n; k ++ )
        {
            memset(f, 0, sizeof f);
            memset(g, 0, sizeof g);
            g[k] = 1;
            int hh = 0, tt = -1;
            for (int i = k; i <= n; i ++ )
            {
                while (hh <= tt && a[i] - a[q[hh]] > m) hh ++ ;
                f[i] = f[q[hh]] + 1;
                if (i == k) f[i] = 0;

                for (int j = hh, t = f[q[hh]]; j <= tt && f[q[j]] == t; j ++ ) g[i] += g[q[j]];

                while (hh <= tt && f[q[tt]] > f[i]) tt -- ;
                q[ ++ tt] = i;
            }

            for (int i = k; i <= n; i ++ )
                if (g[i] == 2)
                    res ++ ;
        }

        printf("%d\n", res);
    }

    return 0;
}
