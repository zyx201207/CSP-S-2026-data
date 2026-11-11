#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int b, c;
	string d, e;
	cin >> b >> d >> c >> e;

	if (b == c) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}

	if (d[0] == e[0] && d[1] == e[1]) {
		cout << 1;
	} else {
		cout << 0 << 0 << 0;
		return 0;
	}

	if ((d[2] == 'D' || d[2] == 'F') && (e[2] == 'D' || e[2] == 'F')) {
		cout << 1;
	} else if ((d[2] == 'A' || d[2] == 'B' || d[2] == 'C') && (e[2] == 'A' || e[2] == 'B' || e[2] == 'C')) {
		cout << 1;
	} else {
		cout << 0 << 0;
		return 0;
	}

	if (d[2] == 'D' && e[2] == 'F' || e[2] == 'D' && d[2] == 'F') {
		cout << 1;
	} else if (d[2] == 'A' && e[2] == 'B' || d[2] == 'B' && e[2] == 'A' || d[2] == 'C' && e[2] == 'B' || d[2] == 'B'
	           && e[2] == 'C') {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}
