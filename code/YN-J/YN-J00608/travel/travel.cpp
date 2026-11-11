#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c3;
	char c2[3], c4[3];
	cin >> c1;
	for (int i = 0; i < 3; i++) {
		cin >> c2[i];
	}
	cin >> c3;
	for (int i = 0; i < 3; i++) {
		cin >> c4[i];
	}
	if (c1 == c3) {
		cout << "1";

		if (c2[0] == c4[0] && c2[1] == c4[1]) {
			cout << "1";

			if ((c2[2] <= 'C' && c4[2] <= 'C') || (c2[2] >= 'D' && c4[2] >= 'D')) {
				cout << "1";
				if ( ( abs(c2[2] - c4[2]) == 1) ) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}

		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}

	return 0;
}