#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ok = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		ok = 1;
	} else {
		cout << 0;
		ok = 0;
	}
	if (ok == 0) {
		cout << 0 << 0 << 0;
	}

	if (ok = 1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1 ;
		ok = 1;
	} else {
		ok = 0;
	}
	if (ok == 0) {
		cout << 0 << 0 << 0 ;
	}
	if (ok = 1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C'
		        && s2[2] == 'B' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D' || s1[2] == 'A' && s2[2] == 'C'
		        || s1[2] == 'C' && s2[2] == 'A') {

			cout << 1;
			ok = 1;
		} else {
			cout << 0;
			ok = 0;
		}
	}
	if (ok == 0) {
		cout << 0;
	}
	return 0;
	if (ok = 1) {
		if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C'
		        && s2[2] == 'B' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D') {

			cout << 1;
			ok = 1;
		} else {
			cout << 0;
			ok = 0;
		}
	}
	return 0;
}
