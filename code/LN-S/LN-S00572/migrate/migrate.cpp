# include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 2e6 + 5;

int c, T, n, to[N][N], cnt;
long long d, a[N], dp[N][N];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", & c, & T);
    while (T --){
        scanf("%d%lld", & n, & d);
        for (int i = 1; i <= n; i ++) scanf("%lld", & a[i]);
        for (int i = 1; i <= n; i ++){
            int l = i, r = n, ans = i;
            while (l <= r){
                int mid = l + r >> 1;
                if (a[mid] - a[i] <= d){
                    ans = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            to[0][i] = i;
            to[1][i] = ans;
        }
        for (int k = 2; k <= n; k ++) for (int i = 1; i <= n; i ++) to[k][i] = to[1][to[k - 1][i]];
        for (int i = 1; i <= n; i ++) for (int j = i; j <= to[1][i]; j ++) dp[i][j] = 1;
        long long cnt = 0;
        for (int i = n - 1; i >= 1; i --) for (int j = i + 1; j <= n; j ++){
            int k;
            for (k = 1; k <= n; k ++) if (to[k][i] >= j) break;
            for (int k1 = 1; k1 < k; k1 ++) for (int xl = to[k1 - 1][i] + 1; xl <= to[k1][i]; xl ++){
                if (to[k - k1][xl] >= j) dp[i][j] += dp[i][xl] * dp[xl][j];
            }
            if (dp[i][j] == 2) cnt ++;
        }
        printf("%lld\n", cnt);
        for (int i = 1; i <= n; i ++) for (int j = 0; j <= n; j ++) dp[i][j] = 0;
    }
    return 0;
}
/*
6 4
-3 0 1 2 3 4
*/
