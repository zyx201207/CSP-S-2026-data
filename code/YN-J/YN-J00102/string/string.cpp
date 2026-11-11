#include <bits/stdc++.h>
#define N 200005
typedef long long ll;

ll n;
ll a[N];
char c[N];
ll sum = 0;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        std::cin >> a[i] >> c[i];
        sum += a[i];
    }
    ll l = 0, r = 0, ans = 0, j = n;
    for (ll i = 1; i <= n; i++)
    {
        l += a[i];
        for (; j >= i; j--)
        {
            if (c[i] == c[j])
            {
                continue;
            }
            if (r + a[j] > l)
            {
                ans += l - r;
                r = l;
                break;
            }
            else
            {
                ans += a[j];
                r += a[j];
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}