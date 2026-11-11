#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int a[200005];
signed main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i][1] = max(dp[i - 1][1], a[i]);
    }
    for (int j = 2; j <= m; j ++) {
        for (int i = 2; i <= n; i ++) {
            dp[i][j] = max(dp[i - 1][j - 1] & a[i], dp[i - 1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}
