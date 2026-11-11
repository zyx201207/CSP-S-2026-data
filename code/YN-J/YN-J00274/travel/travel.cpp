#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool flag = 1;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string t = {01};
	string t1 = {16};

	if (c1 == t || c2 == t || c1 == t1 || c2 == t1) {
		return 0;
	}

	if (c1 == c2) {
		cout << flag;
	} else {
		cout << 0000;
		return 0;
	}

	int n = 0;

	for (int i = 0; i < 2; i++) {

		if (s1[i] != s2[i]) {
			n++;
		}
	}

	if (n == 0) {
		cout << flag;
	} else {
		cout << 0;
	}

	if (s1[2] != s2[2] && (s1[2] = 'A' || 'B' || 'C' ) && (s2[2] = 'A' || 'B' || 'C') ) {
		cout << flag;
	} else if (s1[2] != s2[2] && (s1[2] = 'D' || 'F') && (s2[2] = 'D' || 'F') ) {
		cout << flag;
	} else {
		cout << 0;
	}

	if (abs(s1[2] - s2[2]) == 1) {
		cout << flag;
	} else {
		cout << 0;
	}

	return 0;
}