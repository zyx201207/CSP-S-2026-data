#include <bits/stdc++.h> 
using namespace std ;

long long n ;
int a[500005] = {0} ;
int b [500005] = {0} ;
map < int , int > q ; 
int ccc = 0 ;

bool fin( int x , int k ){
	bool bb = 0 ;
	for (int i = 0 ; i < k ; i++  ) {
		if ( b[i] == x ) {
			bb = 1 ;
			ccc = i ;
			break ;
		}
	} 
	if ( bb == 1 ) {
		for (int i = ccc ; i < k ;i ++) {
			b[i] = -1 ;
		}
		b[ccc] = x ;
	}
	return bb ;
}

int main() {
	freopen( "card.in" , "r" , stdin ) ;
	freopen( "card.out" , "w" , stdout ) ;
	long long m = 0 ;
	cin >> n >>m ;
	for (int i = 0 ; i <n ; i ++ ) {
		cin >>a[i] ; 
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		for (int j = i ;j < n ; j ++ ) {
			if ( ! fin( a[j] , j ) ) {
				b[ccc] = a[j] ;
				ccc ++ ;
			}
		}
		for ( int i = 0 ; i < ccc ; i ++ ) {
			q[b[i]] ++ ; 
		} 
		memset( b , 0 , sizeof( b ) ); 
	}
	for ( int i = 1 ; i <= m ; i ++ ) {
		cout << q[i] << ' ' ;
	}
	
	return 0 ;
}
