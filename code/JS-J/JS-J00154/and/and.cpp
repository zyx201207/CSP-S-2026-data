#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[200005], dp[200005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, maxr = 0;
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
        cin >> a[i];
    dp[0] = a[1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[j] = max(dp[j-1], dp[j-1]&a[i]);
            maxr = max(maxr, dp[j]);
        }
    }
    cout << maxr;
    return 0;
}

