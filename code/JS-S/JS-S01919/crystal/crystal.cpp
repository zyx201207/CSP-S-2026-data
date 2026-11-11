#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500005;
int n, a[N], m, s[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
        if (i == 1) continue;
        int lft = 0, rgh = i + 1;
        while (lft + 1 < rgh)
        {
            int mid = lft + rgh >> 1;
            if (a[i] * mid - (s[i] - s[i - mid]) <= m) lft = mid;
            else rgh = mid;
        }
        ans = max(ans, lft);
    }
    cout << ans << '\n';
    return 0;
}