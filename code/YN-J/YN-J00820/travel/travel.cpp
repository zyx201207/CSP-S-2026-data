#include <iostream>
using namespace std;
int m, n;
string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	m = s1[1] - '0';
	n = s2[1] - '0';

	if (c1 == c2) {
		cout << '1';

		if (m == n) {
			cout << '1';

			if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
				cout << '1';

				if (s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2] ) {
					cout << '1';
				} else {
					cout << '0';
					return 0;
				}
			} else {
				cout << "00";
				return 0;
			}
		}

		else {
			cout << "000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}



	return 0;
}
