#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e6 + 10, N6 = 310, INF = 1e9 + 7;
int c, t;
int n;
ll d;
ll x[N];
int dp[N6][N6][2];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d %d", &c, &t);
    if(c <= 6) {
        while(t --) {
            scanf("%d %lld", &n, &d);
            for(int i = 1;i <= n;i ++) {
                scanf("%lld", &x[i]);
            }
            int ans = 0;
            for(int i = 1;i <= n;i ++) {
                for(int j = 1;j <= n;j ++) {
                    dp[i][j][0] = dp[i][j][1] = 0;
                }
            }
            for(int i = 1;i <= n;i ++) {
                dp[i][i][1] = 1;
            }
            for(int len = 2;len <= n;len ++) {
                for(int i = 1;i <= n - len + 1;i ++) {
                    int l = i, r = i + len - 1;
                    dp[l][r][0] = INF;
                    for(int j = r;j >= l;j --) {
                        if(x[r] - x[j] <= d) {
                            if(dp[l][r][0] == INF) {
                                dp[l][r][0] = dp[l][j][0] + 1;
                                dp[l][r][1] = dp[l][j][1];
                            }else if(dp[l][r][0] == dp[l][j][0] + 1) {
                                dp[l][r][1] += dp[l][j][1];
                            }
                        }
                    }
                    if(dp[l][r][1] == 2) {
                        ans ++;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
