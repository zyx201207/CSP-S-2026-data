#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
constexpr ll inf = LLONG_MIN / 2;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(2, vector<ll>(m + 1, inf));
    vector<ll> nums(n + 1);
    for (ll i = 1;i <= n; i++) {
        cin >> nums[i];
    }
    if (n == 1) {
        cout << nums[1] << endl;
        return 0;
    }
    dp[1][0] = 0;
    dp[1][1] = nums[1];
    for (ll i = 2;i <= n; i++) {
        auto& cur = dp[i & 1], pre = dp[~i & 1];
        cur = pre;
        cur[1] = max(cur[1], nums[i]);
        for (ll j = 2; j <= min(m, i); j++) {
            cur[j] = max(pre[j - 1] & nums[i], cur[j]);
        }
    }
    cout << dp[n & 1][m] << endl;
}
