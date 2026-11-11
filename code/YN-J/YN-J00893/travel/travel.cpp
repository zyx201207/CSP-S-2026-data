/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2026-10-31 08:22
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
string c1, c2;
string z1, z2;
int h1, h2;
char l1, l2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> z1 >> c2 >> z2;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;

	}

	if (z1[0] + z1[1] == z2[0] + z2[1]) {
		cout << 1;

		if ((z1[2] == 'F' || z1[2] == 'D') && (z2[2] == 'F' || z2[2] == 'D')) {
			cout << 1;
		} else if ((z1[2] == 'A' || z1[2] == 'B' || z1[2] == 'C') && (z2[2] == 'A' || z2[2] == 'B' || z2[2] == 'C')) {
			cout << 1;
		} else {
			cout << 0;
			cout << 0;
			return 0;
		}
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= 1; i++) {

		h1 = h1 * 10 + (z1[i] - 48);
		h2 = h2 * 10 + (z2[i] - 48);
	}

	l1 = z1[2];
	l2 = z2[2];

	if (h2 - h1 >= -1 && h2 - h1 <= 1 && l1 - l2 >= -1 && l1 - l2 <= 1) {
		if ((l1 == 'C' && l2 == 'D') || (l1 == 'D' && l2 == 'C')) {
			cout << 0;
			return 0;
		}

		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}

