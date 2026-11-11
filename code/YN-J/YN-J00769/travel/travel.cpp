#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("traxel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2, s1, s2;
	cin >> a1 >> s1 >> a2 >> s2;
	int a = s1[2] - 'A', s = s2[2] - 'A';

	if (a1[1] == a2[1]) {
		cout << 1;

		if (s1[1] == s2[1]) {
			cout << 1;

			if (a - s < 3 && a - s > -3 || a == 3 && s == 4 || a == 4 && s == 3) {
				cout << 1;

				if (a - s == 1 || a - s == -1) {
					cout << 1;
				} else {
					cout << 0;
					return 0;
				}
			} else {
				cout << 00;
				return 0;
			}
		} else {
			cout << 000;
			return 0;
		}
	} else {
		cout << 0000;
		return 0;
	}

	return 0;
}