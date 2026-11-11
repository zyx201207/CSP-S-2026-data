#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("a.in""travel""std.in");
	freopen("a.out""travel""std.out");
	string c1, c2, s1, s2, a, b;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		a += s1[i];
	}
	for (int i = 0; i < 2; i++) {
		b += s2[i];
	}
	if (a == b) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if (a == b && ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
	        || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))) {
		cout << 1;
	} else {
		cout << "00";
		return 0;

	}
	if ((s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'B'
	        && (s2[2] == 'C' || s2[2] == 'A')) || (s1[2] == 'A' && s2[2] == 'B')) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}