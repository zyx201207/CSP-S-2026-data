#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, ans, a[N], sum;

void dfs(int u, int cnt, int res)
{
    if (cnt == m)
    {
        ans = max(ans, res);
        return ;
    }
    if (n - u + 1 < m - cnt) return ;
    dfs (u + 1, cnt + 1, cnt == 0 ? a[u] : res & a[u]), dfs(u + 1, cnt, res);
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], sum &= a[i];
    sort(a + 1, a + n + 1, greater<int>());
    if (n <= 20) dfs(1, 0, 0);
    else if (m == 1) ans = a[1];
    else if (m == n) ans = sum;
    else if (n <= 2000 && m == 2) for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
    else
    {
        ans = a[1];
        for (int i = 2; i <= m; i++) ans &= a[i];
    }
    cout << ans;
    return 0;
}
