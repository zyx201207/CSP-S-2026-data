#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long dp[5005][5005];
long long minn_steps[5005][5005];
long long n, d;
bool check(int i, int j)
{
    if (i == j)
    {
        dp[i][j] = 0;
        minn_steps[i][j] = 0;
        return false;
    }
    if (a[j] - a[i] <= d)
    {
        dp[i][j] = 1;
        minn_steps[i][j] = 1;
        return false;
    }
    if (j - i == 1 && a[j] - a[i] > d)
    {
        dp[i][j] = 0;
        minn_steps[i][j] = 0x3f3f3f3f3f3f3f3f;
        return false;
    }
    if (j - i == 1)
    {
        dp[i][j] = 1;
        minn_steps[i][j] = 1;
        return false;
    }
    for (int k = i; k <= j; k++)
        minn_steps[i][j] = min(minn_steps[i][k] + minn_steps[k][j], minn_steps[i][j]);
    for (int k = i; k <= j; k++)
    {
        if (minn_steps[i][j] == minn_steps[i][k] + minn_steps[k][j] && a[j] - a[k] <= d)
            dp[i][j] += dp[i][k] * dp[k][j];
    }
    return (dp[i][j] == 2);
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    if (c <= 6)
    {
        while (t--)
        {
            cin >> n >> d;
            for (int i = 1; i <= n; i++)
                cin >> a[i];
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dp[i][j] = 0;
                    minn_steps[i][j] = 0x3f3f3f3f3f3f3f3f;
                }
            }
            long long ans = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int l = 1; l <= n - i + 1; l++)
                {
                    int r = l + i - 1;
                    if (check(l, r))
                        ans++;
                }
            }
            cout << ans << endl;
        }
    }
    else if (11 <= c && c <= 12)
    {
        while (t--)
        {
            cin >> n >> d;
            if (n == 1)
            {
                int x;
                cin >> x;
                cout << 0 << endl;
            }
            else
            {
                for (int i = 1; i <= n; i++)
                    cin >> a[i];
                if (a[2] - a[1] >= d)
                    cout << 0 << endl;
                else
                {
                    long long delt = a[2] - a[1];
                    cout << max(0ll, n - (2 * d / delt - 1)) << endl;
                }
            }
        }
    }
    return 0;
}
