#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using Int = long long;
const Int N = 5e5 + 25;
Int n, m, a[N], b[N], l, r, mid, ans = 1;
bool flag1 = true, flag2 = true;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (Int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != i)
            flag1 = false;
    }
    if (flag1)
    {
        cout << ((m + 1) >> 1);
        return 0;
    }
    if (n <= 5000)
    {
        Int cur = 0;
        sort(a + 1, a + n + 1);
        for (Int i = 1; i <= n; i++)
            b[i] = b[i - 1] + a[i];
        for (Int i = 1; i <= n; i++)
            for (Int j = i + 1; j <= n; j++)
            {
                cur = a[j] * (j - i) - b[j - 1] + b[i - 1];
                if (cur <= m)
                    ans = max(ans, j - i + 1);
            }
        cout << ans;
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (Int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    l = 1, r = n;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (a[mid] * (mid - 1) - b[mid - 1] <= m)
            ans = max(ans, mid), l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
