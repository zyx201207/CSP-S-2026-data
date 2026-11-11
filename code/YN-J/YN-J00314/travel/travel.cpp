#include <bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int a, b, c, d, x, y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = (c1[0] - '0') * 10 + c1[1] - '0';
	b = (c2[0] - '0') * 10 + c2[1] - '0';
	c = (s1[0] - '0') * 10 + s1[1] - '0';
	d = (s2[0] - '0') * 10 + s2[1] - '0';
	x = s1[2] - 'A';
	y = s2[2] - 'A';

	if (a == b) {
		cout << "1";

		if (c == d) {
			cout << "1";

			if (x <= 2 && y <= 2) {
				cout << "1";

				if (abs(x - y) == 1) {
					cout << "1";
				} else {
					cout << "0";
				}
			} else if (x > 2 && y > 2) {
				cout << "11";
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
/*
01 01A 01 01B
01 01A 01 01C
01 01A 01 01D
01 01A 01 01F
01 01B 01 01A
01 01B 01 01C
01 01B 01 01D
01 01B 01 01F
01 01C 01 01A
01 01C 01 01B
01 01C 01 01D
01 01C 01 01F
01 01D 01 01A
01 01D 01 01B
01 01D 01 01C
01 01D 01 01F
01 01F 01 01A
01 01F 01 01B
01 01F 01 01C
01 01F 01 01D
*/
