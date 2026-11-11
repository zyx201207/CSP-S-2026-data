#include <bits/stdc++.h>
using namespace std;

int a[100005], c[100005], p[100005];
int n, m, sum, ans = -1;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n>> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        c[i] = a[i + 1] - a[i];
        p[i] = p[i - 1] + c[i];
    }
    int l = n - 1, r = n - 1;
    while (l <= r && l >= 0)
    {
        while (sum <= m && l >= 0)
        {
            sum += p[r] - p[l - 1];
            l--;
        }
        l++;
        ans = max(ans, r - l + 1);
        sum -= c[r] * (r - l + 1);
        sum -= c[l];
        r--;
    }
    cout << ans;
    return 0;
}
