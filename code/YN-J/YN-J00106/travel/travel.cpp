#include <bits/stdc++.h>
using namespace std;
int b[100];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	int  s1, s2;
	char cc1, cc2;
	cin >> c1 >> s1 >> cc1 >> c2 >> s2 >> cc2;

	if (c1 == c2) {
		b[1] = 1;

		if (s1 == s2) {
			b[2] = 1;

			if ((cc1 == 'A' || cc1 == 'B' || cc1 == 'C') && (cc2 == 'A' || cc2 == 'B' || cc2 == 'C')  ) {
				b[3] = 1;

				if ( int (cc1) == int (cc2) + 1 || int (cc1) == int (cc2) - 1) {
					b[4] = 1;
				} else {
					cout << "1110";
					return 0;
				}
			} else {
				if ( (cc1 == 'D' && cc2 == 'F') || (cc2 == 'D' && cc1 == 'F')) {
					b[3] = 1;
					b[4] = 1;
				} else {
					cout << "1100";
					return 0;
				}
			}
		} else {
			cout << "1000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}

	for (int i = 1; i <= 4; i++) {

		cout << b[i];
	}

	return 0;
}