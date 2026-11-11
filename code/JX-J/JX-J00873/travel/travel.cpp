#include <bits/stdc++.h>
using namespace std ;

int r1 , x1 ;
string r2 , x2 ;

int main () {
    ios::sync_with_stdio ( false ) ;
    freopen ( "travel.in" , "r" , stdin ) ;
    freopen ( "travel.out" , "w" , stdout ) ;
    cin >> r1 >> r2 >> x1 >> x2 ;
    if ( r1 == x1 ) {
        cout << 1 ;
        if ( r2 [ 0 ] * 10 + r2 [ 1 ] == x2 [ 0 ] * 10 + x2 [ 1 ] ) {
            cout << 1 ;
            if ( ( r2 [ 2 ] >= 'D' and x2 [ 2 ] >= 'D' ) or ( x2 [ 2 ] < 'D' and r2 [ 2 ] < 'D' ) ) {
                cout << 1 ;
                if ( abs ( ( r2 [ 2 ] - 'A' ) - ( x2 [ 2 ] - 'A' ) ) == 1 ) {
                    cout << 1 ;
                }
                else {
                    cout << "0" ;
                }
            }
            else {
                cout << "00" ;
            }
        }
        else {
            cout << "000" ;
        }
    }
    else {
        cout << "0000" ;
    }
    return 0 ;
}
