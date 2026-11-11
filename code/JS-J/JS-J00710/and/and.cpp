#include <iostream>
using namespace std;
int n, m, a[200010], dp[200010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[m] = a[n];
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp[j] = max(dp[j], dp[j - 1] & a[i]);
        }
    }
    cout << dp[m];
    return 0;
}
