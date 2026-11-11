#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    bool fa = 1, fb = 1;
    long long n, m;
    long long cnt = 0, ans = 0;
    long long t = 0;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (fa && a[i] != i)
            fa = 0;
        if (i > 2 && fb && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
            fb = 0;
    }
    sort(a + 1, a + n + 1);
    if (fa)
    {
        for (int i = n; i >= 1; i--)
        {
            long long s = i * (i - 1) / 2;
            if (s <= m)
            {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    if (fb)
    {
        long long dif = abs(a[1] - a[2]);
        for (int i = n; i >= 1; i--)
        {
            long long s = (i - 1) * (a[i] - a[1] + dif) / 2;
            if (s <= m)
            {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    long long l = a[1], r = a[n] + m;
    while (l <= r)
    {
        t = 0;
        cnt = 0;
        long long mid = (l + r) / 2;
        int ind = upper_bound(a + 1, a + n + 1, mid) - a;
        if (ind > n)
            ind--;
        for (int i = ind; i >= 1; i--)
            if (a[i] <= mid)
            {
                t += mid - a[i], cnt++;
                if (t > m)
                {
                    cnt--;
                    break;
                }
            }
        ans = max(ans, cnt);
        if (t <= m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}