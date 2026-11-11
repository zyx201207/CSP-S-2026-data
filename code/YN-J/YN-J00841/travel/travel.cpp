#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}

	int x1 = 0, r1 = 0;

	for (int i = 0; i < 2; i++) {

		r1 = r1 * 10 + (s1[i] - '0');
		x1 = x1 * 10 + (s2[i] - '0');
	}

	if (r1 == x1) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}

	char r2 = s1[2], x2 = s2[2];

	if ((r2 == 'D' && x2 == 'F') || (r2 == 'F' && x2 == 'D') || ((r2 == 'A' || r2 == 'B' || r2 == 'C') && (x2 == 'A'
	        || x2 == 'B' || x2 == 'C'))) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}

	if ((r2 == 'A' && x2 == 'B') || (r2 == 'B' && (x2 == 'A' || x2 == 'C')) || (r2 == 'C' && x2 == 'B') || (r2 == 'D'
	        && x2 == 'F') || (r2 == 'F' && x2 == 'D')) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}