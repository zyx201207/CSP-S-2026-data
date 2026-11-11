#include <bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> a1 >> a2 >> b1 >> b2;
	if (a1[0] == '1' && b1[0] == '1') {
		if (a1[1] == b1[1]) {
			cout << 1;
		}
	} else if (a1[1] == b1[1]) {
		cout << 1;
	} else {
		cout << "0000\n";
		return 0;
	}
	if (a2[0] == '1' && b2[0] == '1') {
		if (a2[1] == b2[1]) {
			cout << 1;
		}
	} else if (a2[1] == b2[1]) {
		cout << 1;
	} else {
		cout << "000\n";
		return 0;
	}
	if (a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C') {
		if (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C') {
			cout << 1;
		}
	}
	if (a2[2] == 'D' || a2[2] == 'F') {
		if (b2[2] == 'D' || b2[2] == 'F') {
			cout << 1;
		}
	} else {
		cout << "00\n";
		return 0;
	}
	if (a2[2] == 'A' && b2[2] == 'B') {
		cout << 1;
	} else if (a2[2] == 'B' && b2[2] == 'A') {
		cout << 1;
	} else if (a2[2] == 'B' && b2[2] == 'C') {
		cout << 1;
	} else if (a2[2] == 'C' && b2[2] == 'B') {
		cout << 1;
	} else if (a2[2] == 'D' && b2[2] == 'F') {
		cout << 1;
	} else if (a2[2] == 'F' && b2[2] == 'D') {
		cout << 1;
	} else {
		cout << "0\n";
	}

	return 0;
}
