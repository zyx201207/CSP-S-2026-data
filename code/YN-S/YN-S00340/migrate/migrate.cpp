#include <bits/stdc++.h>
using namespace std ;

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	int c, t ;
	cin >>  c >> t ;

	while ( t -- ) {
		int cnt = 0 ;
		int n, d ;
		cin >> n >> d ;
		vector<int> x( n + 1, 0 ) ;

		for ( int i = 1 ; i <= n ; i ++ ) {

			cin >> x[i] ;
		}

		for ( int i = 1 ; i <= n ; i ++ ) {

			for ( int j = 1 ; j <= n ; j ++ ) {

				for ( int z = 1 ; z <= d ; z ++ ) {

					x[i] = x[j] + z ;
					cnt ++ ;
				}
			}

		}

		cout << cnt / d / x[n - 1]  - 1 << "\n" ;
	}

	return 0 ;
}