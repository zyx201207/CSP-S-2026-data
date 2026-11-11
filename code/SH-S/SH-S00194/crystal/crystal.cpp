#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N = 5e5 + 10;
ll a[N], diff[N], n;
ull m;
bool check(ll s, ll len)
{
    ull res = 0;
    for (ll i = s; i <= s + len - 2; i ++)
    {
        ll fact = i - s + 1;
        res += (ull)diff[i] * fact;
    }
    return res <= m;
}
ll bin(ll s)
{
    ll l = 1, r = n - s + 1;
    while (l < r)
    {
        ll mid = l + ((r - l + 1) >> 1);
        // printf("[%lld ,|%lld|, %lld]\n", l, mid, r);
        if (check(s, mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll tempM;
    scanf("%lld %lld", &n, &tempM);
    m = tempM;
    for (ll i = 1; i <= n; i ++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (ll i = 1; i <= n - 1; i ++)
    {
        diff[i] = a[i + 1] - a[i];
    }
    ll ans = 0;
    for (ll s = 1; s <= n; s ++)
    {
        // printf("s=%d\n", s);
        ans = max(ans, bin(s));
    }
    printf("%lld\n", ans);
    return 0;
}