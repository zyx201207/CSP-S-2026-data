#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int n, m;
int main()
{
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int x = 0, f;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (i == 1)
        {
            f = a[1];
        }
        else
        {
            f &= a[i];
        }
        x = max (x, a[i]);
    }
    if (m == n - 1)
    {
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            ans = max (ans, f | a[i]);
        }
        cout << ans;
        return 0;
    }
    if (m == n)
    {
        cout << f;
        return 0;
    }
    if (m == 1)
    {
        cout << x;
        return 0;
    }
    if (m == 2)
    {
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                ans = max (ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    sort (a + 1, a + n + 1);
    cout << a[n - m + 1];
    return 0;
}
