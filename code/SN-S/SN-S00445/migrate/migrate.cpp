//陈梓仁 SN-S 00445


#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll read() {
    ll x = getchar_unlocked(), res = 0, flag = 1;
    for (; x != EOF && (x < '0' || x > '9'); x = getchar_unlocked())
        if (x == '-')
            flag = -1;
    for (; x >= '0' && x <= '9'; x = getchar_unlocked())
        res = res * 10 + x - '0';
    return res * flag;
}
inline ll myabs(ll x) {
    return (x >= 0 ? x : -x);
}
const ll MAXN = 3e3 + 5, MAXLINE = 35;
ll x[MAXN], n, canfly_d;
ll dp_min[MAXN][MAXN], dp[MAXN][MAXN];//dp_min与dp[i][j]分别示从岛屿i到j的最短路大小和有几条
inline bool canfly(ll start, ll end) {
    if (end - start == 1) {
        return x[end] - x[start] <= canfly_d;
    }
    if (end == start)   return false;
    return dp_min[start][end] != 0x3f3f3f3f3f3f3f3f;
}
void solve() {
    n = read(), canfly_d = read();
    ll Min = 0x3f3f3f3f3f3f3f3f;
    for (ll j = 1; j <= n; ++j) x[j] = read(), dp_min[j][j] = 0, dp[j][j] = 1, Min = min(Min, x[j]);
    for (ll j = 1; j <= n; ++j)	x[j] = x[j] - Min;
    for (ll d = 1; d <= n - 1; ++d) {
        for (ll start = 1; start <= n - d; ++start) {
            ll end = start + d;
            if (x[end] - x[start] <= canfly_d) {
                dp_min[start][end] = 1;
                dp[start][end] = 1;
                // cout << "CONTINUE:" << start << " " << end << "DIST:" << x[end] << ":" << x[start] << "TARGET:" << canfly_d << "\n";
                continue;
            }
            for (ll k = start; k <= end; ++k) {
                // 鸟从start -> k -> end
                if (canfly(start, k) && canfly(k, end)) {
                    ll cur_d = dp_min[start][k] + dp_min[k][end];
                	// cout << "DE:CANFLY: " << start << " " << k << " "<< end << "DPMINNEX: " << cur_d << "NOWDPMIN " << dp_min[start][end] << " ADD: " << dp[start][k] * dp[k][end] << " DIST: " << dp_min[start][k] << " " << dp_min[k][end] << "\n";
                    if (cur_d < dp_min[start][end]) {
                        dp_min[start][end] = cur_d;
                        dp[start][end] = dp[start][k] * dp[k][end];
                    } else if(cur_d == dp_min[start][end]) {
                        dp[start][end] += dp[start][k] * dp[k][end];
					}
                }
                else {
                    // cout << "CANNOT FLY:" << start << " " << k << " " << end << "\n";
                }
            }
        }
    }
    
    ll ans = 0;
    for (ll start = 1; start <= n - 1; ++start) {
        for (ll end = start + 1; end <= n; ++end) {
        	// cout << "DE:" << start << " " << end << " " << "DP:" << dp[start][end] << " DPMIN:" << dp_min[start][end] << "\n";
            if (dp[start][end] == 2) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return;
}
int main() {
   freopen("migrate.in", "r", stdin);
   freopen("migrate.out", "w", stdout);
    ll c = read(), t = read();
    while (t--) {
        memset(dp_min, 0x3f, sizeof(dp_min));
        memset(dp, 0, sizeof(dp));
        solve();
    }
    return 0;
}
