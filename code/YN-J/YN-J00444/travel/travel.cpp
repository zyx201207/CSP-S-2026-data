#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int r1, r2;
	int x1, x2;
	char r3, x3;
	cin >> r1 >> r2 >> r3;
	cin >> x1 >> x2 >> x3;
	bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	if (r1 == x1) {
		f1 = 1;
	}

	if (f1 == 1 && r2 == x2) {
		f2 = 1;
	}

	if (f2 == 1 && (((r3 >= 'A' && r3 <= 'C') && (x3 >= 'A' && x3 <= 'C') && x3 != r3)) || ((r3 >= 'D' && r3 <= 'F')
	        && (x3 >= 'D' && x3 <= 'F') && x3 != r3)) {
		f3 = 1;
	}

	if (f3 == 1 && f2 == 1 && f1 == 1) {
		if (r3 == 'A' && x3 == 'B') {
			f4 = 1;
		} else if (r3 == 'B' && (x3 == 'A' || x3 == 'C')) {
			f4 = 1;
		} else if (r3 == 'C' && x3 == 'B') {
			f4 = 1;
		} else if (r3 == 'D' && x3 == 'F') {
			f4 = 1;
		} else if (r3 == 'F' && x3 == 'D') {
			f4 = 1;
		}
	}
	cout << f1 << f2 << f3 << f4;
	return 0;
}