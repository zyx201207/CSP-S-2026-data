#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
#define int long long

int ccc , ttt , n , d , a[N] , ans;

signed main() {
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    scanf ("%lld%lld" , &ccc , &ttt);
    if (ccc == 11 || ccc == 12) {
        for (int _=1; _<=ttt; _++) {
            scanf ("%lld%lld" , &n , &d);
            for (int i=1; i<=n; i++) scanf ("%lld" , &a[i]);
            if (d <= a[2] - a[1]) ans = 0;
            else {
                bool t = false;
                for (int i=2; i<n; i++) {
                    if ((d >= ((a[2] - a[1]) * i)) && (d < ((a[2] - a[1]) * (i+1)))) {
                        ans = n-i+1-i;
                        t = true;
                        break;
                    }
                }
                if (t == false) ans = 0;
            }
            printf ("%lld\n" , ans);
            ans = 0;
        }
        return 0;
    }
    if (ccc == 13 || ccc == 14) {
        for (int _=1; _<=ttt; _++) {
            scanf ("%lld%lld" , &n , &d);
            for (int i=1; i<=n; i++) scanf ("%lld" , &a[i]);
            printf ("%lld\n" , ans);
            ans = 0;
        }
        return 0;
    }
    for (int _=1; _<=ttt; _++) {
        scanf ("%lld%lld" , &n , &d);
        for (int i=1; i<=n; i++) scanf ("%lld" , &a[i]);
        for (int i=1; i<=n-3; i++){
            int j = i+3;
            if (j > n) {
                break;
            }
            int b = 2*d;
            if (j <= n && j-i == 3 && a[j] - a[i] < b && a[j] - a[i] > d) {
                ans++;
            }
        }
        printf ("%lld\n" , ans);
        ans = 0;
    }
    return 0;
}
