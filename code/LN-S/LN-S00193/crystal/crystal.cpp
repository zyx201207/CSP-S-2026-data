#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std ;
const int N = 5e5 + 5 ;
ll n, m, a[N], maxn = 1 ;
ll sum[N], pre[N] ;
signed main () {
    freopen ("crystal.in", "r" , stdin) ;
    freopen ("crystal.out", "w", stdout) ;
    cin >> n >> m ;
    for (int i = 1; i <= n; i ++)  {
        cin >> a[i] ;
        sum[i] = (a[i] - a[i - 1]) * (i - 1) + sum[i - 1] ;
        //cout << "i :" << i << " " << sum[i] << " " ;
    }
    //cout << "\n" ;
    for (int i = n; i >= 1; i --) {
        pre[i] = (a[i + 1] - a[i]) * (n - i) + pre[i + 1] ;
        //cout << "i :" << i << " " << pre[i] << " " ;
    }
    //cout << "\n" ;
    if (n != 1) {
        if (a[2] - a[1] <= m) maxn = 2 ;
        if (a[n] - a[n - 1] <= m) maxn = 2 ;
    }
    for (int i = 2; i <= n - 1; i ++) {
        for (int j = 1; j <= i - 1; j ++) {
            if (i + j > n) break ;
            if ((sum[i] - sum[i - j]) / max (i - j, 1LL) + (pre[i] - pre[i + j]) / max (n - i - j + 1, 1LL) <= m) {
                maxn = max (maxn, j * 2 + 1) ;
            }
            if ((sum[i] - sum[i - j + 1]) / max (i - j - 1, 1LL) + (pre[i] - pre[i + j]) / max (n - i - j + 1, 1LL) <= m) {
                maxn = max (maxn, j * 2) ;
            }
            if ((sum[i] - sum[i - j]) / max (i - j, 1LL) + (pre[i] - pre[i + j - 1]) / max (n - i - j, 1LL) <= m) {
                maxn = max (maxn, j * 2) ;
            }
            //cout << "i: " << i << " j: " << j << " maxn: " << maxn << "\n" ;
        }
    }
    cout << maxn ;
}
