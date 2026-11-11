#include <bits/stdc++.h>
using namespace std ;
long long n , m , a [ 500005 ] , b [ 500005 ] , cnt [ 500005 ] , ans ;
int main ( ) {
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a [ i ] ;
	sort ( a + 1 , a + n + 1 ) ;
	for ( int i = 2 ; i <= n ; i++ ) {
		b [ i ] = a [ i ] - a [ i - 1 ] ;
		if ( cnt [ i - 1 ] + ( ans + 1 ) * b [ i ] <= m ) {
			cnt [ i ] = cnt [ i - 1 ] + ( ans + 1 ) * b [ i ] ;
			ans++ ;
		}
		else cnt [ i ] = cnt [ i - 1 ] + ans * b [ i ] - a [ i - 1 ] + a [ i - ans - 1 ] ;
		//cout << cnt [ i ] << ' ' << ans << endl ; 
	}
	cout << ans + 1 ;
} 
