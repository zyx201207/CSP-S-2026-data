#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 3;
int n, m, a[N], s[N], ans = 1;

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1, j = 2; j <= n; j++)
    {
        int l = j - i + 1, x = a[j] * l, y = s[j] - s[i - 1];
        int z = x - y;
        if (z <= m)
        {
            ans = max(ans, l);
            continue;
        }
        else
        {
            i++;
        }
    }
    cout << ans << '\n';
    return 0;
}
