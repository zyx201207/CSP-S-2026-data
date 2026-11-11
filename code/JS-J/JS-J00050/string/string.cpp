#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    long long a[n], l = 0, r = n - 1;
    long long li = 0, s = 0, ans = 0;
    char c[n], lc;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    for (long long i = 0; i < s / 2; )
    {
        if (a[l] > a[r])
        {
            ans += a[r] * (c[l] != c[r]);
            i += a[r];
            a[l] -= a[r];
            r--;
        }
        else if (a[l] < a[r])
        {
            ans += a[l] * (c[r] != c[l]);
            i += a[l];
            a[r] -= a[l];
            l++;
        }
        else
        {
            ans += a[l] * (c[l] != c[r]);
            i += a[r];
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}
