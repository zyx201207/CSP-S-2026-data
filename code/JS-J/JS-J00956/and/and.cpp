#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
int n, m;
long long a[N];
long long dp[2][N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int I = 1; I <= n; I++) {
        int i = I % 2;
        for (int j = 1; j <= min(I, m); j++) {
            dp[i][j] = max(dp[i ^ 1][j], ((dp[i ^ 1][j - 1] != 0) ? (dp[i ^ 1][j - 1] & a[I]) : a[I]));
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << dp[n % 2][m];
    return 0;
}
