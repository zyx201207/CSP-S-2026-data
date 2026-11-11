#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int rc, xc;
	string rs, xs;
	cin >> rc >> rs >> xc >> xs;
	int rp, xp;
	rp = (rs[0] - '0') * 10 + rs[1] - '0';
	xp = (xs[0] - '0') * 10 + xs[1] - '0';

	if (rc == xc) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (rp == xp) {
		cout << 1;
	} else {
		cout << 0;
	}

	if ((rs[2] <= 'C' && rs[2] <= 'C') || (rs[2] >= 'D' && rs[2] >= 'D')) {
		cout << 1;
	} else {
		cout << 0;
	}

	if ((char(rs[2] + 1) == xs[2]) || (char(rs[2] - 1) == xs[2])) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}