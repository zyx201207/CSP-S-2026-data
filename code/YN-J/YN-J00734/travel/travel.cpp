#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int xr, xx, srn, sxn;
	char srl, sxl;
	cin >> xr >> srn >> srl >> xx >> sxn >> sxl;

	if (xr == xx) {
		cout << 1;

		if (srn == sxn) {
			cout << 1;

			if (srl == 'D' || srl == 'F') {
				if (sxl == 'D' || sxl == 'F') {
					cout << 1 << 1;
				} else {
					cout << 0 << 0;
				}
			} else {
				if (sxl == 'A' || sxl == 'B' || sxl == 'C') {
					cout << 1;
					int x = abs(sxl - srl);

					if (x == 1) {
						cout << 1;
					} else {
						cout << 0;
					}
				} else {
					cout << 0 << 0;
				}
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}

	return 0;
}