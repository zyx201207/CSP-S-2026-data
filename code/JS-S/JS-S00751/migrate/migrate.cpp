#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[2000005];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        int x = d / (a[2] - a[1]);
        if (x <= 1)
            printf("0\n");
        else
        {
            x = 2 * x - 1;
            printf("%lld\n", max(n - x, 0ll));
        }
    }
    return 0;
}
