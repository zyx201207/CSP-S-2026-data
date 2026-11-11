#include<bits/stdc++.h>
using namespace std ;
long long c , cc ;
string s , ss ;
int f(int a , int b) {
	return (a == b) ;
}
int ff(string a , string b) {
	return(a[0] == b[0] && a[1] == b[1]) ;
}
int fff(string a , string b) {
	char k = a[2] , p = b[2] ;
	if(k == 'A') {
		return (p == 'B' || p == 'C') ;
	}
	if(k == 'B') {
		return (p == 'A' || p == 'C') ;
	}
	if(k == 'C') {
		return (p == 'A' || p == 'C') ;
	}
	if(k == 'D') {
		return (p == 'F') ;
	}
	if(k == 'F') {
		return (p == 'D') ;
	}
}
int ffff(string a , string b) {
	char k = a[2] , p = b[2] ;
	if(k == 'A') {
		return (p == 'B') ;
	}
	if(k == 'B') {
		return (p == 'A' || p == 'C') ;
	}
	if(k == 'C') {
		return (p == 'B') ;
	}
	if(k == 'D') {
		return (p == 'F') ;
	}
	if(k == 'F') {
		return (p == 'D') ;
	}
}
int main() {
	freopen("travel.in","r" , stdin) ;
	freopen("tracel.out","w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> c >> s >> cc >> ss ;
	if(f(c , cc )) {
		cout << 1 ;
	} else {
		cout << 0 ;
	}
	if(f(c , cc) && ff(s , ss )) {
		cout << 1 ;
	} else {
		cout << 0 ;
	}
	if(f(c , cc) && ff(s , ss) && fff(s , ss)) {
		cout << 1 ;
	} else {
		cout << 0 ;
	}
	if(f(c , cc) && ff(s , ss) && fff(s , ss) && ffff(s , ss)) {
		cout << 1 ;
	} else {
		cout << 0 ;
	}
	return 0 ;
}
