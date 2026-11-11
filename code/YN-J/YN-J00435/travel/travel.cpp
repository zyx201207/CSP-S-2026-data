#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, k;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		k += '1';

		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			k += '1';

			if ((s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F')) {
				k += "11";
			} else if (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1) {
				if (s1[2] == 'C' && s2[2] == 'D') {
					k += "00";
				} else if (s1[2] == 'D' && s2[2] == 'C') {
					k += "00";
				} else {
					k += "11";
				}
			} else if (s1[2] - s2[2] == 2 || s1[2] - s2[2] == -2) {
				if (s1[2] != 'F' && s2[2] != 'F' && s1[2] != 'D' && s2[2] != 'D') {
					k += "10";
				} else {
					k += "00";
				}
			}

		} else {
			k += "000";
		}
	} else {
		cout << "0000";
	}

	cout << k;

	return 0;
}