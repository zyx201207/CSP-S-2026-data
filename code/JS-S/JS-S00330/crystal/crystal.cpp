#include <bits/stdc++.h>

using namespace std;

#define int long long

const signed N = 5e5 + 10;

int a[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << '\n';

    unsigned int s = 0;
    int l = 1, ans = 1;
    for (int i = 1; i <= n; i++)
    {
        unsigned int tmp = (a[i] - a[i-1]) * (i - l);
        while (tmp > m)
        {
            if (l < i)
            {
                s -= (a[i-1] - a[l]);
                l++;
            }
            tmp = (a[i] - a[i-1]) * (i - l);
        }
        while (s + tmp > m)
        {
            s -= (a[i-1] - a[l]);
            l++;
            tmp = (a[i] - a[i-1]) * (i - l);
        }

        if (s + tmp == m)
        {
            ans = max(ans, i-l+1);
        }
        else
        {
            if (l == 1 && i == n)
                ans = max(ans, i-l);
            else
                ans = max(ans, i-l+1);
        }
        s = s + tmp;
    }
    cout << ans << '\n';

    return 0;
}