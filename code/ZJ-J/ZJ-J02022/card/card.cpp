#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;

long long n , m ;
long long a[N] , b[N] ;
long long t[N] ;

long long check ( long long x ){
	for ( long long i = 1 ; i <= n ; i++ ){
		if ( b[i] == x ){
			return i ;
		}
	}
	return 0 ;
}

int main(){
	freopen( "card.in" , "r" , stdin ) ;
	freopen( "card.out" , "w" , stdout ) ;
	
	cin >> n >> m ;
	
	for ( long long i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	for ( long long i = 1 ; i <= n ; i++ ){
		long long x = 1 ;
		memset ( b , 0 , sizeof(b) ) ;
		for ( long long j = i ; j <= n ; j++ ){
			if ( check( a[j] ) != 0 ){
				x = check( a[j] ) + 1 ;
				for ( long long k = check( a[j] ) + 1 ; k <= n ; k++ ){
					b[k] = 0 ;
				}
			}else{
				b[x] = a[j] ;
				x++ ;
			}
		}
		for ( long long j = 1 ; j <= n ; j++ ){
			t[b[j]] ++ ;
		}
	}
	for ( long long i = 1 ; i <= m ; i++ ){
		cout << t[i] << " " ;
	}
	
	return 0 ;
}
