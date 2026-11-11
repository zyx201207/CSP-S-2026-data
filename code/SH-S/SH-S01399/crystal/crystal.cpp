#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[500010] ;
signed main() {
    freopen("crystal.in","r",stdin) ;
    freopen("crystal.out","w",stdout) ;
    cin.tie(0) ;
    ios::sync_with_stdio(0) ;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
    sort(a+1,a+n+1) ;
    int maxn = -1 ;
    for (int j = a[1] ; j <= a[n] ; j ++ ) {
        int p = lower_bound(a+1,a+n+1,j) - a ;
        int u = upper_bound(a+1,a+n+1,j) - a ;
        int use = 0 , ans = 0 ;
        for (int i = p - 1 ; i >= 1 ; i -- ) {
            use += j - a[i] ;
            if (use > m) {
                maxn = max(ans+u-p,maxn) ;
                break ;
            } else ans ++ ;
        }
        maxn = max(ans,maxn) ;
    }
    cout << maxn ;
    return 0 ;
}
