#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
char c[N];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        if (a[l] > a[r])
        {
            if (c[l] != c[r])
            {
                ans += a[r];
            }
            a[l] -= a[r];
            r--;
        }
        else if (a[l] < a[r])
        {
            if (c[l] != c[r])
            {
                ans += a[l];
            }
            a[r] -= a[l];
            l++;
        }
        else
        {
            if (c[l] != c[r])
            {
                ans += a[l];
            }
            l++;
            r--;
        }
    }
    cout << ans << '\n';
    return 0;
}
