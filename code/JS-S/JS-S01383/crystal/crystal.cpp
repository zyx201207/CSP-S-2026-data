#include <bits/stdc++.h>
using namespace std;

struct N {
    long long ans, re;
};

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<N> dp(n);
    dp[0] = {1, m};
    for (int i = 1; i < n; i++) {
        long long tmp = (a[i] - a[i - 1]) * dp[i - 1].ans;
        if (tmp <= dp[i - 1].re) {
            dp[i] = {dp[i - 1].ans + 1, dp[i - 1].re - tmp};
        } else {
            dp[i] = {1, m};
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i].ans);
    }
    cout << ans << "\n";
    return 0;
}
