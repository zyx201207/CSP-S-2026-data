#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
long long a [N], t [N], sum [N];
int n, f [N], g [N];
long long d;

long long md (long long x)
{
    return (x - 1) % d + 1;
}

void solve (bool flg1)
{
    scanf ("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%lld", a + i);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         printf ("%d ", a [j] - a [i] <= d);
    //     }
    //     printf ("\n");
    // }
    // int cur = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i == 1 || a [i] - t [i - 1] <= d)
    //     {
    //         t [++cur] = a [i];
    //         f [cur - 1][cur] = 1;
    //     }
    // }
    // n = cur;
    long long ans = 0;
    if (flg1)
    {
        for (int j = 2; j <= n; j++)
        {
            f [j] = 0;
        }
        for (int j = 2; j <= n; j++)
        {
            if (a [j] - a [1] <= d)
            {
                f [j] = 1;
                g [j] = 1;
                sum [j] = sum [j - 1] + f [j];
                continue;
            }
            g [j] = 2e9;
            int p = lower_bound (a + 2, a + j, a [j] - d) - a, q = upper_bound (g + p, g + j, g [p]) - g - 1;
            g [j] = g [p] + 1, f [j] = sum [q] - sum [p - 1];
            if (f [j] == 2)
            {
                ans += (n - j + 1);
            }
            // printf ("%d ", f [j]);
            sum [j] = sum [j - 1] + f [j];
        }
        // printf ("\n");
        printf ("%lld\n", ans);
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum [j] = 0;
            f [j] = g [j] = 0;
        }
        sum [i] = 1;
        g [i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            // int cnt = 0;
            g [j] = 2e9;
            int p = lower_bound (a + i, a + j, a [j] - d) - a, q = upper_bound (g + p, g + j, g [p]) - g - 1;
            g [j] = g [p] + 1, f [j] = sum [q] - sum [p - 1];
            if (f [j] == 2)
            {
                ans++;
                // printf ("%d %d\n", i, j);
            }
            // printf ("%d ", f [j]);
            sum [j] = sum [j - 1] + f [j];
        }
        // printf ("\n");
    }
    printf ("%lld\n", ans);
}

int main ()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    int c, t;
    scanf ("%d%d", &c, &t);
    while (t--)
    {
        solve (11 <= c && c <= 12);
    }
    return 0;
}