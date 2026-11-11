#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int d = 0, p = 0, q = 0;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		d = 1;
	} else {
		cout << 0;
	}
	if (d == 1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
		p = 1;
	} else {
		cout << 0;
	}
	if (p == 1 && 'C' >= s1[2] && 'A' <= s1[2] && 'C' >= s2[2] && 'A' <= s2[2] || p == 1 && 'F' >= s1[2] && 'D' <= s1[2]
	        && 'F' >= s2[2]
	        && s2[2] >= 'D') {
		cout << 1;
		q = 1;
	} else {
		cout << 0;
	}
	if (q == 1 && abs(int(s1[2]) - int(s2[2])) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
//02 01A 03 01A