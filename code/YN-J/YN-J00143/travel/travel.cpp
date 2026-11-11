#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int s1, s2, c1, c2;
	string a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	s1 = int(a2[0] - '0') * 10 + int(a2[1] - '0');
	s2 = int(b2[0] - '0') * 10 + int(b2[1] - '0');
	c1 = int(a2[2] - 'A');
	c2 = int(b2[2] - 'A');
	if (c1 < c2) {
		swap(c1, c2);
	}
	if (a1 == b1) {
		cout << '1';
		if (s1 == s2) {
			cout << '1';
			if ((c1 >= 3 && c2 >= 3) || (c1 <= 2 && c2 <= 2)) {
				cout << '1';
				if (c1 - c2 == 1) {
					cout << '1';
				} else {
					cout << '0';
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