#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int n, m, a[N], mx = 0, now = 1, s, diff[N];
signed main ()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 2; i <= n; ++ i)
        diff[i] = a[i] - a[i - 1];
    s = m;
    for (int i = 2; i <= n; ++ i)
    {
        if (now * diff[i] > s)
        {
            mx = max (mx, now);
            s = m;
            now = 0;
            -- i;
            continue;
        }
        s -= (now * diff[i]);
        ++ now;
    }
    if (now * diff[n] > s)
        mx = max (mx, now);
    cout << mx;
    return 0;
}
