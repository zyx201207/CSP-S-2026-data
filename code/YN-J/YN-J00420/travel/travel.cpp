#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int te[4];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << 0;
		te[0] = 0;
	} else {
		cout << 1;
		te[0] = 1;
	}
	if (s1[0] != s2[0] || s1[1] != s2[1] || te[0] == 0) {
		cout << 0;
		te[1] = 0;
	} else {
		cout << 1;
		te[1] = 1;
	}
	if (te[1] == 1) {
		if (('C' >= s1[2] && s1[2] >= 'A') && ('C' >= s2[2] && s2[2] >= 'A')) {
			cout << 1 ;
			te[2] = 1;
		} else if (('D' >= s1[2] && s1[2] >= 'F') && ('D' >= s2[2] && s2[2] >= 'F')) {
			cout << 1 ;
			te[2] = 1;
		} else {
			cout << 0;
			te[2] = 0;
		}
	} else {
		cout << 0;
		te[2] = 0;
	}
	if ((s1[2] - '0' + 1 == s2[2] - '0' || s1[2] - '0' - 1 == s2[2] - '0') && te[2] == 1) {
		cout << 1;
	} else {
		cout << 0;
	}


	return 0;
}