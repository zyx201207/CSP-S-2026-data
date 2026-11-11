#include <bits/stdc++.h>
using namespace std;
int ct1, ct2, pi = 0;
string nc1, nc2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ct1 >> nc1 >> ct2 >> nc2;
	if (ct1 == 01 || ct1 == 16 || ct2 == 01 || ct2 == 16) {
		cout << "0000";
		return 0;
	}
	if (ct1 == ct2) {
		cout << '1';
	} else {
		cout << '0';
	}
	if ((ct1 == ct2) && (nc1 != nc2)) {
		if (nc1[0] + nc1[1] == nc2[0] + nc2[1]) {
			cout << '1';
			pi = 1;
		} else {
			cout << '0';
		}
	} else {
		cout << '0';
	}
	if (pi == 1) {
		if ((nc1[2] - 'A' <= 'C' - 'A' && nc2[2] - 'A' <= 'C' - 'A') || (nc1[2] - 'A' >= 'D' - 'A'
		        && nc2[2] - 'A' >= 'D' - 'A')) {
			cout << '1';
		}
	} else {
		cout << '0';
	}
	if (pi == 1) {
		if (nc1[2] - 'A' <= 'C' - 'A' && nc2[2] - 'A' <= 'C' - 'A') {
			if (nc1[2] - 'A' < nc2[2] - 'A') {
				if (nc1[2] - 'A' + 1 == nc2[2] - 'A') {
					cout << '1';
				} else {
					cout << '0';
				}
			} else if (nc1[2] - 'A' > nc2[2] - 'A') {
				if (nc1[2] - 'A' - 1 == nc2[2] - 'A') {
					cout << '1';
				} else {
					cout << '0';
				}
			}
		} else if (nc1[2] - 'A' >= 'D' - 'A' && nc2[2] - 'A' >= 'D' - 'A') {
			if ((nc1[2] == 'D' && nc2[2] == 'F') || (nc1[2] == 'F' && nc2[2] == 'D')) {
				cout << '1';
			} else {
				cout << '0';
			}
		} else {
			cout << '0';
		}
	} else {
		cout << '0';
	}
	return 0;
}