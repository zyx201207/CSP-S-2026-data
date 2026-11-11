#include <bits/stdc++.h>
using namespace std ;

int n ;
long long a ;
string s , c ;

int main () {
    ios::sync_with_stdio ( false ) ;
    freopen ( "string.in" , "r" , stdin ) ;
    freopen ( "string.out" , "w" , stdout ) ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> a >> c ;
        for ( long long j = 0 ; j < a ; j ++ ) {
            s += c ;
        }
    }
    int si = s . size () / 2 , ans = 0 ;
    for ( int i = 0 ; i < si ; i ++ ) {
        if ( s [ i ] != s [ s . size () - 1 - i ] ) {
            ans ++ ;
        }
    }
    cout << ans ;
    return 0 ;
}
