#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
int c, t, n, d, a[N], b[N], f[N][2], l[N], r[N], s[N][2], b2[N];
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while(t--) {
        scanf("%lld%lld", &n, &d);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            // f[i][0] = 1, f[i][1] = 0, l[i] = 1e18, r[i] = -1e18;
        }
        for(int i = 1; i <= n; i++) {
            b[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
            // if(b[i] != i) {
            //     l[b[i]] = min(l[b[i]], i);
            //     r[b[i]] = max(r[b[i]], i);
            // }
//            printf("%lld ", b[i]);
        }
        if(n <= 300) {
            int ans = 0;
            for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) {
                for(int k = i; k <= j; k++) b2[k] = min(j, b[k]);
                int u = i, cnt = 0;
                while(1) {
                    int v = b2[u];
                    if(u == v) {
                        cnt = 0;
                        break;
                    }
                    if(v == j) break;
                    if(b2[v] == b2[v - 1]) cnt++;
                    if(b2[v] == b2[v - 2]) cnt++;
                    if(cnt > 1) break;
                    u = v;
                }
                if(cnt == 1) {
                    ans++;
                }
            }
            printf("%lld\n", ans);
            continue;
        }
        // for(int i = 1; i <= n; i++) {
        //     for(int j = i; j <= n; j++) cnt[j] = 0;
        //     int u = i;
        //     while(1) {
        //         if(cnt[u] > 1) break;
        //         if(cnt[u] == 1) ans++;
        //         if(u == n) break;
        //         int v = b[u];
        //         cnt[v] += cnt[u];
        //         if(v == u + 1) {
        //             u = v;
        //             continue;
        //         }
        //         if(b[v - 1] == b[v] && b[v] != n) cnt[b[v]]++;
        //         u = v;
        //     }
        //     printf("%lld\n", i);
        //     for(int j = 1; j <= n; j++) printf("%lld ", cnt[j]);
        //     printf("\n");
        // }
        // printf("%lld\n", ans);
        // for(int i = 1; i <= n; i++) {
        //     int x = l[i], y = r[i];
        //     if(x != 1e18) {
        //         if(x == y) {
        //             f[i][0] += f[x][0], f[i][1] += f[x][1];
        //         }
        //         else {
        //             if(l[x] != 1e18) {
        //                 f[i][0] += s[r[x]][0] - s[l[x] - 1][0];
        //                 f[i][1] += s[r[x]][1] - s[l[x] - 1][1];
        //             }
        //             if(l[x + 1] != 1e18) {
        //                 f[i][1] += s[r[x + 1]][0] - s[l[x + 1] - 1][0];
        //             }
        //         }
        //     }
        //     s[i][0] = s[i - 1][0] + f[i][0], s[i][1] = s[i - 1][1] + f[i][1];
        // }
        // for(int i = 1; i <= n; i++) {
        // 	printf("%lld %lld\n", f[i][0], f[i][1]);
		// }
        // printf("ans:%lld\n", ans);
    }
}/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

0 1
10 3
0 3 6 7 8 9 10 11 14 17
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/

