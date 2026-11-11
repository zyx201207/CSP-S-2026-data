#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    vector<int> nxt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int l = i;
        int r = n;

        while (l < r) {
            int mid = l + r + 1 >> 1;
        
            if ((a[mid] - a[i]) <= d) {
                l = mid;
            } else r = mid - 1;
            // if(i == 1) {
            //     cout << mid << "\n";
            //     cout << a[mid] - a[i] << "\n";
            // }
        }
        nxt[i] = l;
        // if (i == 1) {
        //     cout << nxt[i] << "nxt[i]\n";
        // }
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    if (n <= 5000) {
        vector<vector<int>> has(n + 10, vector<int> (n + 10, 0));
        vector<vector<int>> dp(n + 10, vector<int> (n + 10, inf));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (a[i + 1] - a[i] <= d)
            dp[i][i + 1] = 1;
            has[i][i + 1] = 1;
        }
        for (int len = 3; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                // cout << l << " " << r << "---\n";
                if (nxt[l] == l) {
                    dp[l][r] = inf;
                    continue;
                }
                if (nxt[l] >= r) {
                    dp[l][r] = 1;
                    has[l][r] = 1;
                } else {
                    if (dp[l][nxt[l]] == inf || dp[nxt[l]][r] == inf) continue;
                    dp[l][r] = dp[l][nxt[l]] + dp[nxt[l]][r];
                    // if (l == 1 && r == 5) {
                    //     cout << nxt[l] << " ";
                    //     cout << dp[l][nxt[l]] << "||" << dp[nxt[l]][r] << "\n";
                    // }
                    for (int k = nxt[l]; k > l; k--) {
                        if (dp[l][k] + dp[k][r] != dp[l][r]) {
                            break;
                        }   
                        has[l][r] += has[l][k] * has[k][r];
                        if (has[l][r] >= 3) break;
                    }
                }

            }
        }
        // cout << "dp[1][5]:" << dp[1][5] << "\n";
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (has[i][j] == 2) {
                    // cout << i << "OK" << j << "\n";
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    } else if(n > 5000) {
        int diff = a[2] - a[1];
        int flag = true;
        for (int i = 2; i <= n - 1; i++) {
            if (a[i + 1] - a[i] != diff) {
                flag = false;
            }
        }

        if (flag) {
            if (d < diff) {
                cout << 0 << "\n";
                return;
            }
            else if (d >= diff) {
                int can = d / diff;
                if (can == 1) {
                    cout << 0 << "\n";
                    return;
                }

                if (1 + can + (can - 1) > n) {
                    cout << 0 << "\n";
                    return;
                }

                cout << n - can - (can - 1) - 1 + 1 << "\n";
            }

        } else {

        }
    }
}
signed main() {
    freopen("migrate.in", "a+", stdin);
    freopen("migrate.out", "w+", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)  {
        solve();
    }
    return 0;
}