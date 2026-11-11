#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c, t;
ll n, d;
ll ans;
ll x[5005], dp[5005][5005], cnt[5005][5005];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> c >> t;
    while (t--) {
        ans = 0;
        cin >> n >> d;
        for (int i=1; i<=n; i++) cin >> x[i];
        for (int i=1; i<=n; i++) dp[i][i] = 1e18;
        for (int len=2; len<=n; len++) {
            for (int l=1; l+len-1<=n; l++) {
                int r = l + len - 1;
                if (x[r] - x[l] <= d) {
                    dp[l][r] = 2;
                    cnt[l][r] = 1;
                    continue;
                }
                dp[l][r] = 1e18;
                for (int k=l; k<=r; k++) {
                    ll roadl = dp[l][k] + dp[k][r] - 1;
                    if (roadl < dp[l][r]) dp[l][r] = roadl, cnt[l][r] = 1;
                    else if (roadl == dp[l][r]) cnt[l][r]++;
                    if (cnt[l][r] > 2) break;
                }
            }
        }
        for (int l=1; l<=n; l++) {
            for (int r=l+1; r<=n; r++) {
                if (cnt[l][r] == 2) ans++;
                cnt[l][r] = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
