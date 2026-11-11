#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 5e5 + 100;

int a[maxn];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    int n, m;
    scanf("%lld%lld", &n, &m);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + 1 + n);

    int cost = 0;
    int l = 1;

    int ans = 1;

    for(int r = 2; r <= n; ++r)
    {
        cost += (r - l) * (a[r] - a[r-1]);
        while(l < r && cost > m)
        {
            cost -= a[r] - a[l];
            ++l;
        }

        ans = max(ans, r - l + 1);
    }

    printf("%lld\n", ans);
}