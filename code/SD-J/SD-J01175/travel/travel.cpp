#include<bits/stdc++.h>
using namespace std;
#define int long long
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
string s1, st1, s2, st2;
signed main() {
	CLOSE
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> st1 >> s2 >> st2;
	if(s1 == s2) {
		cout << 1 ;
	} else {
		cout << "0000" ;
		return 0;
	}
	if(st1[0] == st2[0] && st1[1] == st2[1]) {
		cout << 1 ;
	} else {
		cout << "000" ;
		return 0;
	}
	if((st1[2] <= 'C' && st2[2] <='C') || (st1[2] >='D' && st2[2] >= 'D')) {
		cout << 1 ;
	} else {
		cout << "00" ;
		return 0;
	}
	if(abs(st1[2] - st2[2]) == 1) {
		cout << 1 ;
	} else cout << 0 ;
}
