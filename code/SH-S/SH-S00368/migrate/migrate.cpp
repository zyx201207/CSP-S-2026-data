#include<bits/stdc++.h>
using namespace std ; 

int c , t ;

int main () {
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	cin >> c >> t ;
	for ( int i = 1 ; i <= t ; i ++ ) {
		long long n , d ;
		cin >> n >> d ;
		long long a[i] = {} ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			cin >> a[i] ;
		}
		if ( a[n] - a[1] <= d ) {
			cout << n-2 << endl ;
			continue ;
		}
		if ( n == 1 ) {
			cout << 0 << endl ;
			continue ;
		}
		if ( n == 2 ) {
			cout << 1 << endl ;
			continue ;
		}
		if ( n >= 4 ) {
			if ( a[n] - a[n-1] == a[n-1] - a[n-2] && a[n-1] - a[n-2] == a[n-2] - a[n-3] ){
				if ( d > a[n] - a[n-2] ) {
					cout << 0 << endl ;
					continue ;
				}
				else {
					cout << n - ( d/(a[n]-a[n-1]) + 1 ) + 1 << endl ;
					continue ;
				}
			}
		}
		long long ans = 0 ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			for ( int j = i+2 ; j <= n ; j ++ ) {
				int counting = 0 ;
				for ( int k = i + 2 ; k <= j ; k ++ ) {
					if ( a[k] - a[k-2] <= d ) {
						counting ++ ;
					}
				}
				if ( counting == 1 ) {
					ans ++ ;
				}
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}
