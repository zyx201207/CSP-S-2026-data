#include <bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string r, x, rz, xz;
	int f = 1;
	cin >> r >> rz >> x >> xz;
	if (r == x) {
		cout << 1;
		if (rz[0] == xz[0] && rz[1] == xz[1]) {
			cout << 1;
			if ((rz[2] == 'A' && xz[2] == 'B') || (xz[2] == 'A' && rz[2] == 'B')) {
				cout << 1;
			} else if ((rz[2] == 'A' && xz[2] == 'C') || (xz[2] == 'A' && rz[2] == 'C')) {
				cout << 1;
			} else if ((rz[2] == 'B' && xz[2] == 'C') || (xz[2] == 'B' && rz[2] == 'C')) {
				cout << 1;
			} else if ((rz[2] == 'D' && xz[2] == 'F') || (xz[2] == 'D' && rz[2] == 'F')) {
				cout << 1;
			} else {
				f = 0;
				cout << 0;
			}
		} else {
			cout << "00";
		}
	} else {
		cout << "000";
	}
	if (abs(rz[2] - xz[2]) == 1 && f == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
