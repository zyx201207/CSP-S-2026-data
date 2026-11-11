#include <bits/stdc++.h>
using namespace std ;
const long long inf = 1e18 + 7 ;
long long c , n , m , d , q , w [ 500005 ] , mp [ 505 ] [ 505 ] ;
struct line {
	long long to , w ;
} ;
vector <line> stop [ 500005 ] ;
int main ( ) {
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> c >> n >> m >> d >> q ;
	for ( int i = 1 ; i <= m ; i++ ) cin >> w [ i ] ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( i == j ) mp [ i ] [ j ] = 0 ;
			else mp [ i ] [ j ] = inf ;
		} 
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		long long k ;
		cin >> k ;
		for ( int j = 1 ; j <= k ; j++ ) {
			long long u , x ;
			cin >> u >> x ;
			for ( int l = 0 ; l < stop [ u ] . size ( ) ; l++ ) {
				long long v = stop [ u ] [ l ] . to , w = stop [ u ] [ l ] . w ;
				mp [ i ] [ v ] = min ( w + x , mp [ i ] [ v ] ) ;
				mp [ v ] [ i ] = mp [ i ] [ v ] ;
			}
			stop [ u ] . push_back ( { i , x } ) ;
		}
	}
	/*for ( int i = 1 ; i <= m ; i++ ) {
		cout << stop [ i ] . size ( ) << endl ;
		for ( int j = 0 ; j < stop [ i ] . size ( ) ; j++ ) 
			cout << stop [ i ] [ j ] . to << ' ' << stop [ i ] [ j ] . w << endl ;
	} 
	cout << endl ;*/
	for ( int k = 1 ; k <= n ; k++ ) {
		for ( int i = 1 ; i <= n ; i++ ) {
			if ( i == k ) continue ;
			for ( int j = 1 ; j <= n ; j++ ) {
				mp [ i ] [ j ] = min ( mp [ i ] [ j ] , mp [ i ] [ k ] + mp [ k ] [ j ] ) ;
			}
		}
	}
	/*for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			cout << mp [ i ] [ j ] << ' ' ; 
		} 
		cout << endl ;
	}*/
	while ( q-- ) {
		long long x , y ;
		cin >> x >> y ;
		long long ans = inf ;
		for ( int i = 0 ; i < stop [ x ] . size ( ) ; i++ ) {
			long long leni = stop [ x ] [ i ] . w , posi = stop [ x ] [ i ] . to ;
			for ( int j = 0 ; j < stop [ y ] . size ( ) ; j++ ) {
				long long lenj = stop [ y ] [ j ] . w , posj = stop [ y ] [ j ] . to ;
				ans = min ( ans , leni + lenj + mp [ posi ] [ posj ] ) ;
			}
		}
		cout << ans + w [ x ] + w [ y ] << endl ; 
	}
}
