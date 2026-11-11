#include <bits/stdc++.h>
using namespace std ;
long long a [ 200010 ] ;
char c [ 200010 ] ;
int main () {
    freopen ("string.in", "r", stdin) ;
    freopen ("string.out", "w", stdout) ;
    int n ; cin >> n ; int li = 1, ri = n ;
    long long s = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a [ i ] >> c [ i ] ;
    while ( li < ri ) {
        if ( c[li] == c[ri] ) {
            if ( a[li] < a[ri] )
                a[ri] -= a[li], li++ ;
            else if ( a[li] > a[ri] )
                a[li] -= a[ri], ri-- ;
            else li++, ri-- ;
        } else {
            if ( a[li] < a[ri] )
                s += a[li], a[ri] -= a[li], li++ ;
            else if ( a[li] > a[ri] )
                s += a[ri], a[li] -= a[ri], ri-- ;
            else s += a[li], li++, ri-- ;
        }
    } cout << s ; fclose (stdin) ; fclose (stdout) ;
    return 0 ;
}
