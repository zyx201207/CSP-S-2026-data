#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int n = 0;

	if (c1 == c2) {
		cout << 1;
		n = 1;
	} else {
		cout << 0;
	}

	int q = 0;

	for (int i = 0; i < 2; i++) {

		if (s1[i] == s2[i] && n == 1) {
			q = 1;
		} else {
			cout << 0;
			q = 0;
			break;
		}
	}

	if (q == 1) {
		cout << 1;
	}

	int m = 0;

	if (q == 1 && n == 1 && s1[2] <= 'C' && s2[2] <= 'C') {
		cout << 1;
		m = 1;
	} else if (q == 1 && n == 1 && s1[2] > 'C' && s2[2] > 'C') {
		cout << 1;
		m = 1;
	} else {
		cout << 0;
		m = 0;
	}

	if (n == 1 && m == 1 && q == 1 && s1[2] - s2[2] == 1) {
		cout << 1;
	}

	if (n == 1 && m == 1 && q == 1 && s2[2] - s1[2] == 1) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}
