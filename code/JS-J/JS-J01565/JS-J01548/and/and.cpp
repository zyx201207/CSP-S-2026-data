#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int a[N];
int dp[N][N];
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[1][i] = a[i];
        tmp = max(tmp, a[i]);
    }
   // sort (a + 1, a + n + 1);
    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = max((dp[i - 1][k] & a[j]), dp[i][j]);
            }
        }
    }
    int maxn = 0, maxi;
    for (int i = 1; i <= n; i++)
    {
        maxn = max(maxn, dp[m][i]);
        if (maxn == dp[m][i])
        {
            maxi = i;
        }
    }
    cout << maxn << '\n';
    return 0;
}
