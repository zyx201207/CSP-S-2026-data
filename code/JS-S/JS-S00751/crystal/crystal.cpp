#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], pre[500005], ans;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    if (n <= 5000)
    {
        ans = 1;
        for (int i = 2; i <= n; i++)
        {
            int cnt = 1, sum = 0;
            for (int j = i - 1; j >= 1; j--)
            {
                sum += (a[i] - a[j]);
                if (sum <= m)
                    cnt++;
                else
                    break;
            }
            ans = max(ans, cnt);
        }
    }
    else
    {
        if (a[1] <= 100 && a[n] >= -100 && m <= 1e8)
        {
            ans = 1;
            int sum = 0, cnt = 1, j = a[1], id = 1;
            while (j == a[id + 1])
                id++;
            while (j < a[n])
            {
                j++, sum += cnt;
                while (sum > m)
                    sum -= (j - a[id - cnt + 1]), cnt--;
                while (j == a[id + 1])
                    cnt++, id++, ans = max(ans, cnt);
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
                pre[i] = pre[i - 1] + a[i];
            for (int i = n; i >= 1; i--)
            {
                if (a[i] * i - pre[i] <= m)
                {
                    ans = i;
                    break;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
