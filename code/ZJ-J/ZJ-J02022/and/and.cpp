#include<bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10 ;

long long n , m ;
long long a[N] ;
long long mx[N] ;
long long b[10010][10010] ;

int main(){
	freopen( "and.in" , "r" , stdin ) ;
	freopen( "and.out" , "w" , stdout ) ;
	
	cin >> n >> m ;
	for ( long long i = 1 ; i <= n ; i++ ){
		scanf( "%lld" , &a[i] ) ;
		mx[i] = a[i] ;
	}
	for ( long long i = 1 ; i < m ; i++ ){
		for ( long long j = 1 ; j <= n ; j++ ){
			long long maxn = 1 , t ;
			for ( long long k = 1 ; k <= n && k != j ; k++ ){
				if ( ( mx[j] & a[k] ) > maxn && !b[j][k] ){
					maxn = ( mx[j] & a[k] ) ;
					long long t = k ;
				}
			}
			mx[j] = maxn ;
			b[j][t] = 1 ;
		}
	}
	long long ans = 0 ;
	for ( long long i = 1 ; i <= n ; i++ ){
		ans = max( ans , mx[i] ) ;
	}
	cout << ans ;
	
	return 0 ;
}
