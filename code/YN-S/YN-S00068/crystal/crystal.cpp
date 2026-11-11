#include <bits/stdc++.h>
#define N 500005
typedef long long ll;

ll n, m, a[N];
ll ans = 0;

void f()
{
    for (ll i = 1; i <= n; i++)
    {
        ll k = 0;
        for (ll j = i; j >= 1; j--)
        {
            k += a[i] - a[j];
            if (k > m)
            {
                ans = std::max(ans, i - j);
                break;
            }
            if (j == 1)
            {
                ans = std::max(ans, i);
            }
        }
    }
}
ll k;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    std::sort(a + 1, a + n + 1);
    if (n <= 5005)
    // if (false)
    {
        f();
    }
    else
    {
        k = a[2] - a[1];
        for (ll i = 2; i <= n; i++)
        {
            if (i * a[i] - (i * (a[1] + a[i]) / 2) > m)
            {
                ans = i - 1;
                break;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}