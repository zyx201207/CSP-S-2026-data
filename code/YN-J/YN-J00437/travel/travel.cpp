#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[2], s1[3], c2[2], s2[3];

	for (int i = 0; i < 2; i++) {

		cin >> c1[i];
	}

	for (int i = 0; i < 3; i++) {

		cin >> s1[i];
	}

	for (int i = 0; i < 2; i++) {

		cin >> c2[i];
	}

	for (int i = 0; i < 3; i++) {

		cin >> s2[i];
	}

	if ((c1[0] == c2[0]) && (c1[1] == c2[1])) {
		cout << 1;

		if ((s1[0] == s2[0]) && (s1[1] == s2[1])) {
			cout << 1;

			if (((s1[2] - 'A' < 3) && (s2[2] - 'A' < 3)) || ((s1[2] - 'A' > 3) && (s2[2] - 'A' > 3))) {
				cout << 1;
			} else {
				cout << 0;
			}

			if (s1[2] - s1[2] == 1 || s1[2] - s2[2] == -1) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}


	return 0;
}
