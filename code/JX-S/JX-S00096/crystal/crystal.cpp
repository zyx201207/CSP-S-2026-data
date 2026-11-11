#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[500010], b[500010], ans;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 3; i <= n; ++i)
    {
        if (a[i] - a[i - 1] == a[2] - a[1]) ++ans;
    }
    if (ans == n - 2)
    {
        for (int i = 1; i <= m / (a[2] - a[1]); ++i)
        {
            if (i * (i + 1) / 2 > m / (a[2] - a[1]))
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0, cnt = 0;
        for (int j = i; j >= 1; --j) b[j] = a[i] - a[j];
        for (int j = 1; j <= i; ++j)
        {
            if (b[j] + sum <= m) ++cnt, sum += b[j];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}


