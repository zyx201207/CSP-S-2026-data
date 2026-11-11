#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N = 2e6 + 5 ;
int c, t ;
int n, d ;
int x[N] ;
int v1[N], v2[N] ;
signed main () {
    freopen ("migrate.in", "r", stdin) ;
    freopen ("migrate.out", "w", stdout) ;
    cin >> c >> t ;
    while (t --) {
        int ans = 0 ;
        cin >> n >> d ;
        for (int i = 1; i <= n; i ++) {
            cin >> x[i] ;
            v1[i] = LLONG_MAX - 1 ;
            v2[i] = LLONG_MIN + 1 ;
        }
        for (int i = 1; i <= n - 3; i ++) {
            if (x[i + 1] - x[i] <= d && x[i + 2] - x[i] <= d && x[i + 3] > d) {
                if (x[i + 3] - x[i + 1] <= d) {
                    ans ++ ;
                }
            }
        }
        cout << ans << "\n" ;
    }
}
