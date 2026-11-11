#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int dp[2000005];
void solve() {
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    int gc = x[2] - x[1];
    dp[1] = 1;
    for(int i = 1; i <= n; i++) {
        int len = 0;
        for(int j = i; j <= n ;j++) {
            len += x[j];
            if(len <= d) {
                dp[j] += dp[i];
            }
        }
    }
    int cnt= 0;
    for(int i = 1; i <= n; i++) {
        if(dp[i] == 2) {
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        solve();
    }

    return 0;
}
