#include<bits/stdc++.h>
using namespace std;

const int N = 2e3+5;
int a[N];
int n, m;
int dp[N][N];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = a[i];
    }

    for (int j = 2; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= n; ++k) {
                if (k != i)
                    dp[i][j] = max(dp[i][j], dp[k][j-1] & a[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i ) ans = max(ans, dp[i][m]);
    cout << ans;
    return 0;
}
