#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 9;
int c, t;
LL a[N], d;
int n;
int f[N];
int dp[N];
int check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] - a[1] <= d && a[n] - a[i] <= d)
            return i;
    return 0;
}
bool check2()
{
    for (int i = 2; i <= n; i++)
        if (a[i] - a[i - 1] != a[2] - a[1])
            return false;
    return true;
}
void solve()
{
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if (check2())
    {
        d /= (a[2] - a[1]);
        LL ans = 0;
        if (d <= 1 || 2 * d >= n)
        {
            printf("0\n");
            return;
        }
        printf("%lld\n", n - 2 * d + 1);
        return;
    }
    if (check() && (LL)n * n > 1e8)
    {
        int x = check();
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int ind = n, s = 0;
            if (a[n] - a[i] > d)
                ind = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
            if (ind == x)
                ind--, s = 1;
            if (ind <= i)
                continue;
            int ind2 = upper_bound(a + 1, a + n + 1, a[ind] + d) - a - 1;
            ind += s;
            ans += ind2 - ind;
        }
        printf("%lld\n", ans);
        return;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        dp[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            while (l < j && a[j] - a[l] > d)
                l++;
            if (l == j)
                break;
            f[j] = f[l] + 1;
            dp[j] = dp[l];
            for (int k = l + 1; k < j; k++)
            {
                if (f[k] != f[l])
                    break;
                dp[j] += dp[k];
                if (dp[j] >= 3)
                    continue;
            }
            dp[j] = min(dp[j], 3);
            ans += (dp[j] == 2);
        }
    }
    printf("%lld\n", ans);
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
        solve();
}
