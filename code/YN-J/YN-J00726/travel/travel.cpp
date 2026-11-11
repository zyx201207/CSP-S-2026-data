#include <bits/stdc++.h>
using namespace std;
int a, b;
string s, s1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> s >> b >> s1;
	char c = s[2];
	char c1 = s1[2];
	if (a == b) {
		cout << 1;
		if (s[0] == s1[0] && s[1] == s1[1]) {
			cout << 1;
			if (c <= 'C' && c1 <= 'C') {
				cout << 1;
				if (max(c - c1, c1 - c) == 1 ) {
					cout << 1 ;
				} else {
					cout << 0 ;
				}
			} else if (c >= 'D' && c1 >= 'D') {
				cout << 1;
				if (max(c - c1, c1 - c) == 1 ) {
					cout << 1 ;
				} else {
					cout << 0 ;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
}