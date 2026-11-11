#include<bits/stdc++.h>
using namespace std;

int x[2000005], dp[2000005], s[2000005];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, t, n, d;
    cin >> c >> t;
    while(t--) {
            int ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            s[i] = x[i] - x[1];
        }
        int j = 1;
        while (1) {
            dp[j] = 1;
            if (s[j] > d) {
                break;
            }
            j++;
        }
        for (int k = j; k <= n; k++) {
            for (int l = 1; l < d; l++) {
                dp[k] = dp[s[k]-d+l] + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 2) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
