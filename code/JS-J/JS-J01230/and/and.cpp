#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
int dp[MAX];
int n, m;
int a[MAX];


int main() {
    freopen("and3.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    memset(dp, 255, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    if (n > 60827) {
        for (int i = 1; i <= m; i++) {
            // for (int j = m; j >= 1; j--) {
            //     dp[j] = max(dp[j], dp[j - 1] & a[i]);
            // }
            dp[m] = dp[m] & a[i];
        }
    }
    else {
        for (int i = 1; i <= m; i++) {
            for (int j = m; j >= 1; j--) {
                dp[j] = max(dp[j], dp[j - 1] & a[i]);
            }
        }
    }

    // for (int i =1; i <= m; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << '\n';
    cout << dp[m] << '\n';
    fclose(stdin);
    fclose(stdout);
}