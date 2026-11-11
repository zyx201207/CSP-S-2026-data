#include <bits/stdc++.h>
using namespace std ;
long long c , t , n , d , a [ 2000005 ] , l [ 2000005 ] , r [ 2000005 ] , dp [ 2000005 ] , cnt [ 2000005 ] , ans , flagg2 ;
bool flag = 1 , flag2 = 0 ;
long long getint ( ) {
	long long f = 1 , x = 0 , c = getchar ( ) ;
	for ( ; ! isdigit ( c ) ; c = getchar ( ) ) if ( c == '-' ) f = -1 ;
	for ( ; isdigit ( c ) ; c = getchar ( ) ) x = x * 10 + c - '0' ;
	return x * f ;
}
int main ( ) {
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout ) ;
	c = getint ( ) ;
	t = getint ( ) ;
	while ( t-- ) {
		flag = 1 , flag2 = 0 ;
		n = getint ( ) ;
		d = getint ( ) ;
		int f = 1 ;
		for ( int i = 1 ; i <= n ; i++ ) {
			a [ i ] = getint ( ) ;
			if ( a [ i ] - a [ i - 1 ] != a [ i - 1 ] - a [ i - 2 ] && i > 2 ) flag = 0 ;
			while ( a [ i ] - a [ f ] > d ) {
				r [ f ] = i - 1 ;
				f++ ;
			}
			l [ i ] = f ;
		}
		if ( flag == 1 ) {
			d /= a [ 2 ] - a [ 1 ] ;
			if ( d == 1 || d == 0 ) cout << 0 << endl ;
			else cout << max ( 0ll , n - d * 2 + 1 ) << ' ' << 1 << endl ;
			continue ;
		}
		for ( int i = f ; i <= n ; i++ ) {
			r [ i ] = n ;
			if ( l [ i ] == 1 && flag2 == 0 ) flag2 = 1 , flagg2 = i ;
		}
		ans = 0 ;
		/*if ( flag2 == 1 ) {
			for ( int i = 1 ; i < flagg2 ; i++ ) {
				if ( r [ i ] > flagg2 + 1 ) break ;
				for ( int j = flagg2 + 1 ; j <= n ; j++ ) {
					if ( l [ j ] + 1 == r [ i ] ) ans++ ;
					//cout << i << ' ' << j << ' ' << ans << endl ;
				}
			}
			cout << ans << ' ' << 2 << endl ;
			continue ;
		}*/
		for ( int i = 1 ; i <= n ; i++ ) {
			for ( int j = i ; j <= n ; j++ ) dp [ j ] = 1e9 + 7 , cnt [ j ] = 0 ;
			dp [ i ] = 0 ;
			cnt [ i ] = 1 ;
			for ( int j = i ; j <= n ; j++ ) {
				//cout << i << ' ' << j << ' ' << dp [ j ] << ' ' << cnt [ j ] << endl ;
				for ( int k = r [ j ] ; k > j ; k-- ) {
					if ( dp [ j ] + 1 == dp [ k ] ) {
						cnt [ k ] += cnt [ j ] ;
					}
					if ( dp [ j ] + 1 < dp [ k ] ) {
						dp [ k ] = dp [ j ] + 1 ;
						cnt [ k ] = cnt [ j ] ;
					}
					if ( dp [ j ] + 1 > dp [ k ] ) break ;
					if ( r [ k ] < r [ j ] ) break ;
				}
				//cout << cnt [ j ] << ' ' << dp [ j ] << ' ' ;
				if ( cnt [ j ] == 2 ) { ans++ ; }
			}
			//cout << endl ;
		}
		cout << ans << endl ;
	}
	
} 
