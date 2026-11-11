#include <bits/stdc++.h>
using namespace std ;

int n , m ;
vector < int > a ;

int main () {
    ios::sync_with_stdio ( false ) ;
    //freopen ( "and.in" , "r" , stdin ) ;
    //freopen ( "and.out" . "w" , stdout ) ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ ) {
        int num ;
        cin >> num ;
        a . push_back ( num ) ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ) {
            for ( int l = 0 ; l < n ; l ++ ) {
                if ( i == j or j == l or i == l ) {
                    continue ;
                }
                else {
                    ans = max ( ans , a [ i ] & a [ j ] & a [ l ] ) ;
                }
            }
        }
    }
    cout << ans ;
    return 0 ;
}
