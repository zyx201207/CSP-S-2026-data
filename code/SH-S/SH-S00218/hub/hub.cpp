#include <bits/stdc++.h>
using namespace std ;
long long c , t , n , k , mxn [ 100005 ] = { 1 } , len , cnt [ 100005 ] , root ;
vector <long long> a [ 100005 ] ;
long long dfs ( long long u , long long fa ) {
	long long res = 0 ;
	for ( int i = 0 ; i < a [ u ] . size ( ) ; i++ ) {
		if ( a [ u ] [ i ] != fa ) res = max ( res , dfs ( a [ u ] [ i ] , u ) ) ;
	}
	return res + 1 ;
} 
void cntans ( long long u , long long fa , long long c ) {
	c += 2 ;
	for ( int i = 0 ; i < a [ u ] . size ( ) ; i++ ) {
		if ( a [ u ] [ i ] != fa ) cntans ( a [ u ] [ i ] , u , c ) ;
		if ( a [ u ] [ i ] != fa ) cnt [ c ] ++ ;
	}
} 
int main ( ) {
	freopen ( "hub.in" , "r" , stdin ) ;
	freopen ( "hub.out" , "w" , stdout ) ;
	cin >> c >> t ;
	while ( t-- ) {
		cin >> n >> k ;
		for ( int i = 1 ; i <= n ; i++ ) a [ i ] . clear ( ) ;
		for ( int i = 1 ; i < n ; i++ ) {
			int u , v ;
			cin >> u >> v ;
			a [ u ] . push_back ( v ) ;
			a [ v ] . push_back ( u ) ;
		}
		for ( int i = 1 ; i <= n ; i++ ) {
			if ( a [ i ] . size ( ) == 1 ) len = max ( len , dfs ( i , 0 ) ) ;
		}
		len *= 2 ;
		for ( int j = 1 ; j <= len ; j++ ) mxn [ j ] = 0 ;
		for ( int i = 1 ; i <= n ; i++ ) {
			for ( int j = 0 ; j <= len ; j++ ) cnt [ j ] = 0 ;
			root = i ;
			cntans ( i , 0 , 0 ) ;
			cnt [ 0 ] = 1 ;
			for ( int j = 2 ; j <= len ; j += 2 ) if ( cnt [ j ] ) cnt [ j ]-- , cnt [ j - 1 ] ++ ;
			for ( int j = 1 ; j <= len ; j++ ) cnt [ j ] += cnt [ j - 1 ] ;
			//for ( int j = 0 ; j <= len ; j++ ) cout << cnt [ j ] << ' ' ;
			//cout << endl ;
			for ( int j = 1 ; j <= len ; j++ ) mxn [ j ] = max ( mxn [ j ] , cnt [ j ] ) ;
		}
		//cout << len << endl ;
		for ( int i = 0 ; i <= len ; i++ ) {
			//cout << mxn [ i ] << ' ' ;
			if ( mxn [ i ] >= k ) {
				cout << i << endl ;
				break ;
			}
		}
	}
} 
