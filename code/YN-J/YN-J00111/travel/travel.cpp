#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1[0] == c2[0] && c1[1] == c2[1]) {

		if (s1[0] == s2[0] && s1[1] == s2[1]) {

			int num1 = int(s1[2]);
			int num2 = int(s2[2]);

			if ((num1 <= 67 && num2 <= 67) || (num1 > 67 && num2 > 67)) {

				if (abs(num1 - num2) == 1) {
					cout << 1 << 1 << 1 << 1;
					return 0;
				} else {
					cout << 1 << 1 << 1 << 0;
					return 0;
				}
			} else {
				cout << 1 << 1 << 0 << 0;
				return 0;
			}
		} else {
			cout << 1 << 0 << 0 << 0;
			return 0;
		}
	} else
		cout << 0 << 0 << 0 << 0;
	return 0;

}
