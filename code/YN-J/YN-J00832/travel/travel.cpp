#include <bits/stdc++.h>
using namespace std;
string rc, rz, xc, xz;
bool tx = true, tp = true, tc = true;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rc >> rz >> xc >> xz;
	if (rc == xc) {
		cout << 1;
	} else {
		cout << 0;
		tx = false;
	}
	if (tx && rz[0] == xz[0] && rz[1] == xz[1]) {
		cout << 1;
	} else {
		cout << 0;
		tp = false;
	}
	if (tx && tp && ((rz[2] >= 'A' && rz[2] <= 'C' && xz[2] >= 'A' && xz[2] <= 'C') || ((rz[2] == 'D' || rz[2] == 'F')
	                 && (xz[2] == 'D' || xz[2] == 'F')))) {
		cout << 1;
	} else {
		cout << 0;
		tc = false;
	}
	if (tx && tp && tc && ((rz[2] - xz[2] == 1 || xz[2] - rz[2] == 1) || ((rz[2] == 'D' || rz[2] == 'F')
	                       && (xz[2] == 'D' || xz[2] == 'F')))) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}