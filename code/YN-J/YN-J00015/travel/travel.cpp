#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string xx, xz, rx, rz;
	cin >> xx >> xz >> rx >> rz;
	if (xx == rx) {
		cout << 1;
		string xq, xh, rq, rh;
		xq = xz[0] + xz[1];
		xh = xz[2];
		rq = rz[0] + rz[1];
		rh = rz[2];
		if (xq == rq) {
			cout << 1;
			int a, b;
			if (xh == "A" || xh == "B" || xh == "C") {
				a = 1;
			} else {
				a = 2;
			}
			if (rh == "A" || rh == "B" || rh == "C") {
				b = 1;
			} else {
				b = 2;
			}
			if (a == b) {
				cout << 1;
				if (abs(xh[0] - rh[0]) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}

