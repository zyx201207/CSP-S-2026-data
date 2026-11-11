#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c, d;
	string a, b;
	cin >> c;
	for (int i = 0; i < 3; i++) {

		cin >> a[i];
	}
	cin >> d;

	for (int i = 0; i < 3; i++) {

		cin >> b[i];
	}

	if (c == d) {
		cout << '1';

		if (a[0] == b[0] && a[1] == b[1]) {
			cout << '1';

			if (a[2] == 'A' || a[2] == 'B' || a[2] == 'C') {
				if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C') {
					cout << '1';

					if (a[2] == 'A') {
						if (b[2] == 'B') {
							cout << '1';
						}
					} else if (a[2] == 'A' && b[2] != 'B') {
						cout << '0';
					}

					if (a[2] == 'B') {
						if (b[2] == 'A' || b[2] == 'C') {
							cout << '1';
						}
					} else if (a[2] == 'B' && b[2] != 'A' && b[2] != 'C') {
						cout << '0';
					}

					if (a[2] == 'C') {
						if (b[2] == 'B') {
							cout << '1';
						}
					} else if (a[2] == 'C' && b[2] != 'B') {
						cout << '0';
					}
				}
			} else if (a[2] == 'D' || a[2] == 'F') {
				if (b[2] == 'D' || b[2] == 'F') {
					cout << '1';

					if (a[2] == 'D') {
						if (b[2] == 'F') {
							cout << '1';
						}
					} else if (a[2] == 'D' || b[2] != 'F') {
						cout << '0';
					}

					if (a[2] == 'F') {
						if (b[2] == 'D') {
							cout << '1';
						} else if (a[2] == 'F' && b[2] != 'D') {
							cout << '0';
						};
					}
				}
			} else {
				cout << "00";
				return 0;
			};
		} else if (a[1] != b[1] || a[0] != b[0]) {
			cout << "000";
			return 0;
		};
	} else if (c != d) {
		cout << "0000";
		return 0;
	};

	return 0;
}