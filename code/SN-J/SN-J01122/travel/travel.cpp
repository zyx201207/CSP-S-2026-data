#include <bits/stdc++.h>
using namespace std ;
string a , b , c , d ;
int main() {
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	cin >> a >> b >> c >> d ;
	if (a == c) {
		cout << '1' ;
		string s1 = b.substr(0 , 2) ;
		string s2 = d.substr(0 , 2) ;
		if (s1 == s2) {
			cout << '1' ;
			char A = b[2] , B = d[2] ;
			if ((A == 'F' && B == 'D') || (A == 'D' && B == 'F') || (A == 'A' && B == 'B') || (A == 'A' && B == 'C') || (A == 'B' && B == 'C') || (A == 'B' && B == 'A') || (A == 'C' && B == 'A') || (A == 'C' && B == 'B')) {
				cout << '1' ;
				if ((A == 'A' && B == 'C') || (A == 'C' && B == 'A')) {
					cout << '0' ;
				}
				else {
					cout << '1' ;
				}
			}
			else {
				cout << "00" ;
			}
		}
		else {
			cout << "000" ;
		}
	}
	else {
		cout << "0000" ;
	}
	return 0 ;
} 
