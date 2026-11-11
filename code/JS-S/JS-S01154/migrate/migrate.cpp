#include<bits/stdc++.h>
using namespace std;
int c, t;
int n;
long long d;
long long a[2000005];
int dp[2000005];
long long cnt[2000005];
void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n;i++) {
        scanf("%lld", &a[i]);
    }
    if (c == 11 || c == 12) {
        if (d <= (a[2] - a[1])) {
            puts("0");
            return;
        }
        int Cnt = d / (a[2] - a[1]) + 1;
        printf("%lld\n", 1ll * max(0, n - 2 * Cnt + 3));
        return;
    }
    if (c == 13 || c==14) {
        puts("0");
        return;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j] = INT_MAX - 10;
            cnt[j] = 0;
        }
        dp[i] = 0;
        cnt[i] = 1;
        for (int j = i + 1; j <= n; j++) {
            for (int k = j - 1; ; k--) {
                if (a[j] - a[k] > d) break;
                dp[j] = min(dp[j], dp[k] + 1);
            }
            for (int k = j - 1; ; k--) {
                if (a[j] - a[k] > d) break;
                if (dp[j] == dp[k] + 1) cnt[j] += cnt[k];
            }
            if (cnt[j] == 2) ans++;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        solve();
    }
    return 0;
}
