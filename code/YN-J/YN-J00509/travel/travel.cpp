#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int n = 0, m = 0;

	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (s1[1] == s2[1] && (c1 == c2)) {
		if (s1[2] == s2[2]) {
			cout << "1";
			n++;
		}
	} else {
		cout << "0";
	}

	if (((n == 1 && s1[3] >= 'D' && s2[3] >= 'D') || (n == 1 && s1[3] <= 'C' && s2[3] <= 'C')) && (c1 == c2)) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (c1 == c2) {
		if ((s1[3] == 'F' && s2[3] == 'D') || (s1[3] == 'D' && s2[3] == 'F')) {
			cout << "1";
			m = 1;
		}

		if ((s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'A')) {
			cout << "1";
			m = 1;
		}

		if ((s1[3] == 'B' && s2[3] == 'C') || (s1[3] == 'C' && s2[3] == 'B')) {
			cout << "1";
			m = 1;
		}
	}

	if (m == 0) {
		cout << m;
	}


	return 0;
}