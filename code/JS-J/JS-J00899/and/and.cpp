#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5, M = 2e5 + 5;
int n, m;
int a[M], cnt[5];
int dp[N][N];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        dp[i][1] = a[i];
    }
    if (m == 1)
    {
        cout << maxn;
        return 0;
    }
    if (m == 2)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if (m == n)
    {
        int ans = a[1];
        for (int i = 1; i <= n; i++) ans &= a[i];
        cout << ans;
        return 0;
    }
    if (maxn < 4)
    {
        for (int i = 1; i <= n; i++) cnt[a[i]]++;
        if (m <= cnt[3]) cout << 3;
        else if (m <= cnt[2] + cnt[3]) cout << 2;
        else if (m <= cnt[1] + cnt[3]) cout << 1;
        else cout << 0;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}
