#include <bits/stdc++.h>
using namespace std ;

string c1, s1, c2, s2 ;
bool ac1, ac2, ac3 ;

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen( "travel.in", "r", stdin ) ;
	freopen( "travel.out", "w", stdout ) ;

	cin >> c1 >> s1 >> c2 >> s2 ;

	if ( c1 == c2 ) {
		cout << 1 ;
		ac1 = true ;
	} else
		cout << 0 ;

	string a, b ;
	char k1 = s1[2], k2 = s2[2] ;

	for ( int i = 0 ; i < 2 ; i ++ ) {

		a += s1[i] ;
		b += s2[i] ;
	}

	if ( a == b && ac1 ) {
		cout << 1 ;
		ac2 = true ;
	} else
		cout << 0 ;

	bool r1 = false, l1 = false, r2 = false, l2 = false ;

	if ( k1 >= 'A' && k1 <= 'C' ) {
		r1 = true ;
	} else {
		l1 = true ;
	}

	if ( k2 >= 'A' && k2 <= 'C' ) {
		r2 = true ;
	} else {
		l2 = true ;
	}

	if ( ac1 && ac2 && r1 && r2) {
		ac3 = true ;
		cout << 1 ;
	} else if ( ac1 && ac2 && l1 && l2 ) {
		ac3 = true ;
		cout << 1 ;
	} else {
		cout << 0 ;
	}

	if ( ac1 && ac2 && ac3 && k2 - k1 == 1 )
		cout << 1 ;
	else
		cout << 0 ;
	return 0 ;
}