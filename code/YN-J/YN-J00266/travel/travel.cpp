#include <bits/stdc++.h>
using namespace std;
int r, x;
string r1, x1, a[4], r2, x2, r3, x3, r4, x4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r >> r1 >> x >> x1;
	r2 = r1[0], r3 = r1[1], x2 = x1[0], x3 = x1[1], r4 = r1[2], x4 = x1[2];
	if (r != x) {
		cout << "0000";
	} else {
		a[1] = '1';
		if (r2 == x2 && r3 == x3) {
			a[2] = '1';
			if (r4 == "A" && x4 == "B" || r4 == "B" && x4 == "A" || r4 == "B" && x4 == "c" || r4 == "c" && x4 == "B" || r4 == "A"
			        && x4 == "C" || r4 == "C" && x4 == "A" || r4 == "D" && x4 == "F" || r4 == "F" && x4 == "D") {
				a[3] = '1';
				if (r4 == "A" && x4 == "B" || r4 == "B" && x4 == "A" || r4 == "B" && x4 == "c" || r4 == "c" && x4 == "B" || r4 == "D"
				        && x4 == "F" || r4 == "F" && x4 == "D") {
					a[4] = '1';
				} else {
					a[4] = '0';
				}
			} else {
				a[3] = '0';
				a[4] = '0';
			}
		} else {
			a[2] = '0';
			a[3] = '0';
			a[4] = '0';
		}
		cout << a[1] + a[2] + a[3] + a[4];
	}
	return 0;
}
