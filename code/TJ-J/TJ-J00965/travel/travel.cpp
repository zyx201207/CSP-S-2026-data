#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int f1( string s1, string s2 ) {
	s1 = s1[ 0 ] + s1[ 1 ];
	s2 = s2[ 0 ] + s2[ 1 ];
	return ( s1 == s2 );
}

int f2( string s1, string s2 ) {
	char c1{ s1[ 2 ] };
	char c2{ s2[ 2 ] };
//	cout << c1 << c2 << endl;
	return ( c1 == 'D' and c2 == 'E' ) or ( c2 == 'D' and c1 == 'E' ) or ( c1 != 'D' and c1 != 'F' and c2 != 'D' and c2 != 'F' );
}

int f3( string s1, string s2 ) {
	char c1{ s1[ 2 ] }, c2{ s2[ 2 ] };
	return ( c1 - c2 == 1 or c2 - c1 == 1 );
}

int main() {
	freopen( "travel.in", "r", stdin );
	freopen( "travel.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << ( c1 == c2 );
	cout << ( c1 == c2 and f1( s1, s2 ) );
	cout << ( c1 == c2 and f1( s1, s2 ) and f2( s1, s2 ) );
	cout << ( c1 == c2 and f1( s1, s2 ) and f2( s1, s2 ) and f3( s1, s2 ) );
	return 0;
}
