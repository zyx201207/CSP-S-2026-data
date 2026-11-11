#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		int c11 = (s1[0] - '0') * 10 + (s1[1] - '0');
		int c22 = (s2[0] - '0') * 10 + (s2[1] - '0');
		if (c11 == c22) {
			cout << 1;
			int c111 = (s1[2] - 'A');
			int c222 = (s2[2] - 'A');
			if ((c111 >= 3 && c222 >= 3) || (c111 <= 2 && c222 <= 2)) {
				cout << 1;
				if (c111 - c222 == 1 || c222 - c111 == 1) {
					cout << 1;
				} else {
					cout << 0;
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