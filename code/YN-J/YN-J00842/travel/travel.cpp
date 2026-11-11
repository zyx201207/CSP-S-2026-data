#include <bits/stdc++.h>
using namespace std;

int rx, xx, rm, xm, rs, xs;
string rz, xz;

int main() {
	freopen("traval.in", "r", stdin);
	freopen("traval.out", "w", stdout);

	cin >> rx >> rz >> xx >> xz;

	rm = rz[2];
	xm = xz[2];

	rs = (rz[0] - 48) * 10 + rz[1] - 48;
	xs = (xz[0] - 48) * 10 + xz[1] - 48;

	if (rx != xx) {
		cout << "0000";

		return 0;
	}
	cout << 1;

	if (rs != xs) {
		cout << "000";

		return 0;
	}
	cout << 1;

	if (rm == 67 && xm == 68) {
		cout << "00";

		return 0;
	}
	if (xm == 67 && rm == 68) {
		cout << "00";

		return 0;
	}
	cout << 1;

	if (abs(xm - rm) != 1) {
		cout << "0";

		return 0;
	}

	cout << 1;

	return 0;
}