#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int dan[10];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> c1 >> s1 >> c2 >> s2;

	int ok = 0;

	for (int i = 0; i < c1.size(); i++) {

		if (c1[i] != c2[i]) {
			dan[1] = 0;
			ok = 1;
			break;
		}
	}

	if (ok == 0) {
		dan[1] = 1;
	}

	if (dan[1] == 1) {
		ok = 0;

		for (int i = 0; i < s1.size() - 1; i++) {

			if (s1[i] != s2[i]) {
				dan[2] = 0;

				dan[3] = 0;
				ok = 1;
				break;
			}
		}

		if (ok == 0) {
			dan[2] = 1;

			if (s1[2] == 'C' && s2[2] == 'D') {
				dan[3] = 0;
				ok = 1;
			}

			if (s1[2] == 'D' && s2[2] == 'C') {
				dan[3] = 0;
				ok = 1;
			}

			if (ok == 0) {
				dan[3] = 1;
			}
		}

		if (dan[3] == 0) {
			dan[4] = 0;
		} else {
			if (s1[2] == 'A' && s2[2] == 'B') {
				dan[4] = 1;
			}

			if (s1[2] == 'B' && s2[2] == 'A') {
				dan[4] = 1;
			}

			if (s1[2] == 'B' && s2[2] == 'C') {
				dan[4] = 1;
			}

			if (s1[2] == 'C' && s2[2] == 'B') {
				dan[4] = 1;
			}

			if (s1[2] == 'D' && s2[2] == 'F') {
				dan[4] = 1;
			}

			if (s1[2] == 'F' && s2[2] == 'D') {
				dan[4] = 1;
			}
		}
	}



	for (int i = 1; i <= 4; i++) {

		cout << dan[i];
	}

	return 0;
}