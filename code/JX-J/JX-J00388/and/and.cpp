#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[200010], ans1, n, m;
void dfs(int step, int ans, int cnt)
{
    if (cnt == m)
    {
        ans1 = max(ans1, ans);
        return;
    }
    if (step > n) return;
    if (cnt < m)
    {
        if (!ans) dfs(step + 1, a[step], cnt + 1);
        else dfs(step + 1, ans & a[step], cnt + 1);
    }
    dfs(step + 1, ans, cnt);
}
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (m == 1)
    {
        cout << a[n] << endl;
        return 0;
    }
    if (m == n)
    {
        ans1 = a[1];
        for (int i = 2; i <= n; ++i) ans1 &= a[i];
        cout << ans1 << endl;
        return 0;
    }
    if (m == 2 && n <= 2000)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j) ans1 = max(ans1, a[i] & a[j]);
        }
        cout << ans1 << endl;
        return 0;
    }
    if (a[n] < 4)
    {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 1) ++cnt1;
            if (a[i] == 2) ++cnt2;
            if (a[i] == 3) ++cnt3;
        }
        if (cnt3 >= m) cout << "3\n";
        else if (cnt2 + cnt3 >= m) cout << "2\n";
        else if (cnt1 + cnt3 >= m) cout << "1\n";
        else cout << "0\n";
        return 0;
    }
    dfs(1, 0, 0);
    cout << ans1 << endl;
    return 0;
}
