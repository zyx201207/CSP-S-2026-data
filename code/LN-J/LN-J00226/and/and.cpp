#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], cnt = -1;
void dfs(long long x, long long s, long long k)
{
    if (x == n + 1)
    {
        if (k != m) return ;
        cnt = max(cnt, s);
        return ;
    }
    if (k > m) return ;
    dfs(x + 1, s & a[x], k + 1);
    dfs(x + 1, s, k);
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (n == 1)
    {
        cout << a[1] << "\n";
        return 0;
    }
    if (m == 1)
    {
        cout << a[n] << "\n";
        return 0;
    }
    if (m == n)
    {
        long long ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans << "\n";
        return 0;
    }
    if (n <= 2000 && m == 2)
    {
        long long ans = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << "\n";
        return 0;
    }
    if (n <= 20)
    {
        dfs(1, pow(2, 20) - 1, 0);
        cout << cnt << "\n";
        return 0;
    }
    return 0;
}
