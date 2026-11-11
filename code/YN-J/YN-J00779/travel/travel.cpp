#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x1, x2, r1, r2;
	cin >> x1 >> x2 >> r1 >> r2;
	if (x1 == r1) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if (x2[0] == r2[0] && x2[1] == r2[1]) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}
	bool t = 0;
	if ((x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C') && (r2[2] == 'A' || r2[2] == 'B' || r2[2] == 'C')) {
		cout << 1;
	} else if ((x2[2] == 'D' || x2[2] == 'F') && (r2[2] == 'D' || r2[2] == 'F')) {
		cout << 1;
		t = 1;
	} else {
		cout << 0 << 0;
		return 0;
	}
	if (t == 1) {
		cout << 1;
	} else if (abs(x2[2] - r2[2]) == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}