#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		int a = 0, b = 0;

		for (int i = 0; i <= 1; i++) {

			a = a * 10 + s1[i] - '0';
			b = b * 10 + s2[i] - '0';
		}

		if (a == b) {

			if (s1[2] >= 'D' && s2[2] >= 'D' || s1[2] <= 'C' && s2[2] <= 'C') {
				int x = int(s1[2]), y = int(s2[2]);

				if (abs(x - y) == 1) {
				} else {
					cout << "1110";
					return 0;
				}
			} else {
				cout << "1100";
				return 0;
			}
		} else {
			cout << "1000";
			return 0;
		}
	} else {
		cout << "0000";
		return 0;
	}

	cout << "1111";
	return 0;
}