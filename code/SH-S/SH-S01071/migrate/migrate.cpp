#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 7;
int c, t, n, d, a[N];
// 98min
// testcase1~10  40pts  O(N^2)
void solve1()
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        vector<int> dis(n + 7, 1e18), ct(n + 7, 0), pre(n + 7, 0);
        dis[i] = 0, ct[i] = 1, pre[i] = 1;
        for (int j = i + 1, l = i, r = i; j <= n; j++)
        {
            while (l < j && a[j] - a[l] > d)
                l++;
            if (l == j)
                break;
            r = max(l, r);
            while (r < j && dis[l] == dis[r + 1])
                r++;
            dis[j] = dis[l] + 1, ct[j] = pre[r] - pre[l - 1], pre[j] = pre[j - 1] + ct[j], ans += (ct[j] == 2);
        }
    }
    cout << ans << endl;
}
// testcase11~12  8pts  O(1)
void solve2()
{
    if (n == 1)
        cout << 0 << endl;
    else if (d / (a[2] - a[1]) > 1)
        cout << max(0LL, n - (d / (a[2] - a[1]) * 2 - 1)) << endl;
    else
        cout << 0 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (c == 11 || c == 12)
            solve2();
        else
            solve1();
    }
    return 0;
}