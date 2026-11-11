#include <bits/stdc++.h>
using namespace std ;
long long a [ 2000010 ] ;
int dp [ 2000010 ] ;
int main () {
    freopen ("migrastal.in", "r", stdin) ;
    freopen ("migrastal.out", "w", stdout) ;
    int t ; cin >> t >> t ;
    while ( t-- ) {
        int n ; long long d ; cin >> n >> d ;
        for ( int i = 1 ; i <= n ; i++ )
            cin >> a [ i ] ;
        for ( int i = 5 ; i <= n ; i++ ) {
            dp [ i ] = 1 ;
            for ( int j = i - 1 ; j >= 1 && a[i]-a[j] <= d ; j-- )
                dp [ i ] += dp [ j ] ;
        } cout << dp [ n ] << endl ;
    }flocse (stdin) ; fclose (stdout) ;
    return 0 ;
}
