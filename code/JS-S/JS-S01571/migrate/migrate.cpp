// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// int c, t, n, d, a[2000010];
// unordered_multiset<int> dp[2000010];
// signed main()
// {
//     freopen("migrate2.in", "r", stdin);
//     // freopen("migrate.out", "w", stdout);
//     scanf("%lld%lld", &c, &t);
//     for (int b = 0; t--; b = 0)
//     {
//         scanf("%lld%lld", &n, &d);
//         for (int i = 1; i <= n; i++)
//             scanf("%lld", a + i), dp[i].clear();
//         for (int i = 1; i <= n; i++)
//             for (int j = i + 1; j <= n && a[j] - a[i] <= d; j++)
//             {
//                 dp[i][j].emplace(i);
//                 int tmp = dp[j].count(i);
//                 if (tmp == 2)
//                 {
//                     b++;
//                     cout << i << ' ';
//                 }
//                 else if (tmp == 3)
//                     b--;
//             }
//         printf("%lld\n", b);
//     }
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, a[2000010];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    for (int b = 0; t--; b = 0)
    {
        scanf("%lld%lld", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        for (int i = 1; i <= n; i++)
            for (int j = i + 3; j <= n; j++)
                if (a[j] - a[i] > d && (a[j] - a[i]) % d)
                {
                    int ta = i, bl = 1;
                    int prev = 0, cnt = 0;
                    while (ta < j)
                    {
                        ta = upper_bound(a + 1, a + n + 1, a[i] + bl * d) - a, bl++;
                        cnt += ta - prev;
                        prev = ta;
                    }
                    int tb = upper_bound(a + 1, a + n + 1, a[j] - d) - a;
                    // printf("%lld %lld\n", cnt, tb);
                    if (cnt - tb + 1 == bl)
                        b++;
                }
        printf("%lld\n", b);
    }
}