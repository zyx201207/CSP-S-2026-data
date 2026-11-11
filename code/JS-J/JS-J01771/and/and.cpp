#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[200005];
int n, m, f = 1, ans = -1;

void dfs(int s, int k, int z, int p)
{

    if (k == 0)
    {
        ans = max(ans, z);
 //       cout << ans << "\n";
        return ;
    }
    if (s > n) return ;
    dfs(s + 1, k, z, n);
    int e = s + 1;
    dfs(s + 1, k - 1, (z & a[e]), n);
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    int maxn = -111;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        if (a[i] != i - 1) f = 0;
    }
    if (m == 1)
    {
        cout << maxn << "\n";
        return 0;
    }
    if (m == 2)
    {
        int maxs = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                maxs = max(maxs, (a[i] & a[j]));
            }
        }
        cout << maxs << "\n";
        return 0;
    }
    if (m == n)
    {
        int ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans = (ans & a[i]);
        }
        cout << ans << "\n";
        return 0;
    }
    if (maxn < 4)
    {
        cout << 3 << "\n";
        return 0;
    }
    if (f == 1)
    {
        cout << 0;
        return 0;
    }
    if (m == n - 1)
    {
        int ans = -1;
        int p = 2147483647;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i != k) p = (p & a[i]);
            }
            ans = max(ans, p);
        }
        cout << p << "\n";
        return 0;
    }
    if (n <= 20)
    {
        int s = 2147483647;
        dfs(0, m, s, n);
        cout << ans << "\n";
        return 0;
    }
    sort(a + 1, a + n + 1);
    cout << a[n - m + 1];
    return 0;
}
