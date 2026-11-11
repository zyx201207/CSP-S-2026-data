#include <bits/stdc++.h>
using namespace std ;
#define ll long long

ll n, L, cnt ;
string s ;

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen( "string.in", "r", stdin ) ;
	freopen( "string.out", "w", stdout ) ;
	cin >> n ;

	for ( int i = 1 ; i <= n ; i ++ ) {

		ll a ;
		char c ;

		cin >> a >> c ;
		L += a ;
		s.resize( L, c ) ;
	}

	ll l = 0, r = L - 1 ;

	while ( l <= r ) {
		if ( s[l] != s[r] ) {
			cnt ++ ;
		}

		l ++ ;
		r -- ;
	}

	cout << cnt ;
	return 0 ;
}