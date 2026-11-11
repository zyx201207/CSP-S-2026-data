#include <bits/stdc++.h>
using namespace std ;
int a[500010], t[500010], c[500010], x[500010] ;
bool f [ 500010 ] ;
int main () {
    freopen ("card.in", "r", stdin) ;
    freopen ("card.out", "w", stdout ) ;
    int n, m, xi ; cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a [ i ] ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            f [ j ] = false ;
            t [ j ] = 0 ;
        } xi = i ;
        for ( int j = i ; j <= n ; j++ ) {
            if ( f [ j ] )
                xi = t [ j ] ;
            else t[xi] = a[j], xi++ ;
            f [ j ] ^= true ;
        } for ( int j = i ; j <= xi ; j++ )
             c[t[j]]++ ;
    } for ( int i = 1 ; i <= m ; i++ )
        cout << c [ i ] << ' ' ;
    fclose (stdin) ; fclose (stdout) ;
    return 0 ;
}
