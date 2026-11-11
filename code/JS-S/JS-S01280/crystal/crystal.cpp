#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll maxn = 5e5 + 5;

ll n, m, a[maxn];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for (ll i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    sort(a, a + n, less<ll>());
    ll l = 0, r = 0;
    ll sum = 0, ans = 1;
    while (r < n)
    {
        if (r != 0)
            sum += (r - l) * (a[r] - a[r - 1]);
        //cerr << "sum = " << sum << ", l = " << l << ", r = " << r << '\n';
        while (sum > m)
        {
            sum -= a[r] - a[l];
            ++l;
        }
        //cerr << "new sum = " << sum << ", l = " << l << ", r = " << r << '\n';
        ans = max(ans, r - l + 1);
        ++r;
    }
    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
