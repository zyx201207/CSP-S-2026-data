#include <bits/stdc++.h>
using namespace std;
long long read()
{
    long long k = 1, ans = 0;
    char ch = getchar_unlocked();
    while (!isdigit(ch))
    {
        if (ch == '-')
            k = -1;
        ch = getchar_unlocked();
    }
    while (isdigit(ch))
    {
        ans = ans * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return ans * k;
}
const int N = 5e5 + 5;
long long n, m, a[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort (a + 1, a + n + 1);
    long long ans = 1, l = 1, r = 1, v = 0;
    while (l <= r && r < n)
    {
        if (m >= v + (a[r + 1] - a[r]) * (r - l + 1))
        {
            v += (a[r + 1] - a[r]) * (r - l + 1);
            r++;
        }
        else
        {
            v -= a[r] - a[l - 1];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}
