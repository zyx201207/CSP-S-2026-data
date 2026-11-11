#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector<int> dp, a;
signed main() {
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp.resize(k + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = (i > k) ? k : i; j >= 1; j--) {
            if (j == 1) dp[j] = max(a[i], dp[j]);
            else dp[j] = max(dp[j], a[i] & dp[j - 1]);
        }
    }
    cout << dp[k];
    return 0;
}