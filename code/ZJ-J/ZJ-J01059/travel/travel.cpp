#include<bits/stdc++.h>
using namespace std;

#define int long long
string s1, s2, p1, p2;

inline int c(char a, char b) {
	if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C') return 1;
	else if((a == 'D' || a == 'F') && (b == 'D' || b == 'F')) return 1;
	return 0;
}

inline int c2(char a, char b) {
	if (a > b) swap(a, b);
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) return 1;
	return 0;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> s1 >> p1 >> s2 >> p2;
	if (s1 == s2) {
		cout << '1';
	} else {
		cout << '0';
	}
	if (s1 == s2 && p1[0] == p2[0] && p1[1] == p2[1]) {
		cout << '1';
	} else {
		cout << '0';
	}
	if (s1 == s2 && p1[0] == p2[0] && p1[1] == p2[1] && c(p1[2], p2[2])) {
		cout << '1';
	} else {
		cout << '0';
	}
	if (s1 == s2 && p1[0] == p2[0] && p1[1] == p2[1] && c2(p1[2], p2[2])) {
		cout << '1';
	} else {
		cout << '0';
	}
	return 0;
}
