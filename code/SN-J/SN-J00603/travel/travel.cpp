#include <bits/stdc++.h> 
using namespace std ;

int main() {
	freopen( "travel.in" , "r" , stdin ) ;
	freopen( "travel.out" , "w" , stdout ) ;
	long long c1 = 0 , c2 = 0 ;
	string s1 , s2 ;
	cin >> c1 >>s1 >>c2 >>s2 ;
	bool cc = 0 ;
	if ( c1 == c2 ) {
		cout <<1 ;
		cc = 1 ;
	}else {
		cout << 0 ;
	}
	bool bb = 0 ;
	if ( s1[0] == s2[0] && s1[1] == s2[1] && cc == 1 ) {
		cout << 1 ;
		bb = 1 ;
	}else {
		cout << 0 ;
	}
	if ( ( s1[2] >= 'D' && s2[2] >= 'D' ) || ( s1[2] <= 'C' && s2[2] <= 'C' ) && bb == 1 ) {
		cout << 1 ;
		if ( abs( s1[2] - s2[2] ) == 1 ) {
			cout << 1 ;
		}else {
			if ( s1[2] >= 'D' && s2[2] >= 'D' ) {
				cout << 1 ;
			}else {
				cout << 0 ;
			}
		}
	}else {
		cout << 0 ;
		cout << 0 ;
	}
		
	return 0 ;
}
