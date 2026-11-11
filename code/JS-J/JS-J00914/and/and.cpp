#include<bits/stdc++.h>
#define FILENAME "and"
using namespace std;

const int full_mask = 2147483647;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dp(m + 1, 0);
    dp[0] = full_mask;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp[j] = max(dp[j], dp[j - 1] & a[i]);
        }
    }
    cout << dp[m];
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}