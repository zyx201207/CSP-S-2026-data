#include <bits/stdc++.h>
using namespace std ;
int n ; long long m, a [ 500010 ] ;
bool check ( int x ) {
    for ( int i = 1 ; i <= n - x + 1 ; i++ )
        if ( abs ( a[i] - a[i+x-1] ) <= m )
            return true ;
    return false ;
}
int main () {
    freopen ("crystal.in", "r", stdin) ;
    freopen ("crystal.out", "w", stdout) ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a [ i ] ;
    int l = 1, r = n, ax = 0 ;
    sort ( a + 1, a + n + 1 ) ;
    while ( l <= r ) {
        int mid = l + ( r - l ) / 2 ;
        if ( check ( mid ) ) {
            ax = mid ;
            l++ ;
        } else r-- ;
    } cout << ax ;
    fclose (stdin) ; fclose (stdout) ;
    return 0 ;
}
