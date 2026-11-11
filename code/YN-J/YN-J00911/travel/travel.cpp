#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0' << '0';
		return 0;
	}

	if (s1[0] == s2[0] and s1[1] == s2[1]) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0';
		return 0;
	}

	if (s1[2] == 'C' and s2[2] == 'D') {
		cout << '0' << '0';
		return 0;
	}

	if (s1[2] == 'D' and s2[2] == 'C') {
		cout << '0' << '0';
		return 0;
	}

	if (s1[2] == 'A' or 'B' or 'C') {
		if (s2[2] == 'A' or 'B' or 'C' and s1[2] == 'A' or 'B' or 'C') {
			if (s2[2] != 'D' or 'F' and s1[2] != 'D' or 'F') {
				cout << '1';

				if ((s1[2] - s2[2] == 1 or s2[2] - s1[2] == 1) and (s2[2] != 'D' or 'F' and s1[2] != 'D' or 'F')) {
					cout << '1';
				} else {
					cout << '0';
					return 0;
				}
			}
		} else {
			cout << '0' << '0';
			return 0;
		}
	} else if (s1[2] == 'D' or 'F') {
		if (s2[2] == 'D' or 'F' and s1[2] == 'D' or 'F') {
			if (s2[2] != 'A' or 'B' or 'C' and s1[2] != 'A' or 'B' or 'C') {
				cout << '1' ;

				if ((s1[2] - s2[2] == 1 or s2[2] - s1[2] == 1) and (s2[2] != 'A' or 'B' or 'C' and s1[2] != 'A' or 'B' or 'C')) {
					cout << '1';
				} else {
					cout << '0';
					return 0;
				}

			} else {
				cout << '0' << '0';
				return 0;
			}
		}
	}

	return 0;
}