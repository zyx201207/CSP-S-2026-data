#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int l1, r1, l2, r2, l3, r3;
	string a, b;
	cin >> l1 >> a >> r1 >> b;
	r2 = 10 * (b[0] - '0') + (b[1] - '0');
	l2 = 10 * (a[0] - '0') + (a[1] - '0');
	r3 = b[2] - 64;
	l3 = a[2] - 64;
	if (l3 == 6) {
		l3 = 5;
	}
	if (r3 == 6) {
		r3 = 5;
	}
	bool a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	if (l1 == r1) {
		a1 = 1;
		if (r2 == l2) {
			a2 = 1;
			if ((l3 <= 3 && r3 <= 3) || (l3 > 3 && r3 > 3)) {
				a3 = 1;
				if (abs(l3 - r3) == 1 && ((l3 == 3 && r3 == 4) || (l3 == 4 && r3 == 3)) == 0) {
					a4 = 1;
				}
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
	return 0;
}