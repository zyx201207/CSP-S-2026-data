#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, bb, a[500010], b[500010];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[i] * (i - mid) - b[i - 1] + b[mid - 1] > m)
                l = mid + 1;
            else
            {
                r = mid - 1;
                ans = mid;
            }
        }
        if (ans != -1)
            bb = max(bb, i - ans + 1);
    }
    printf("%lld", bb);
}