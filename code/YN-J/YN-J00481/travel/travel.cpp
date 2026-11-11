#include <bits/stdc++.h>
using namespace std;
int x, y;
string s, z;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> s >> y >> z;
	if (x != y) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
	}
	if (s[0] == z[0] && s[1] == z[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (s[2] == 'A' || s[2] == 'B' || s[2] == 'C') {
		if (z[2] == 'A' || z[2] == 'B' || z[2] == 'C') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	} else if (s[2] == 'D' || s[2] == 'F') {
		if (z[2] == 'D' || z[2] == 'F') {
			cout << "1";
		} else {
			cout << "00";
			return 0;
		}
	}
	if (s[2] == 'A') {
		if (z[2] == 'B')
			cout << "1";
		else
			cout << "0";
	} else if (s[2] == 'B') {
		if (z[2] == 'C' || z[2] == 'A') {
			cout << "1";
		} else {
			cout << "0";
		}
	} else if (s[2] == 'C') {
		if (z[2] == 'B') {
			cout << "1";
		} else {
			cout << "0";
		}
	} else if (s[2] == 'D') {
		if (z[2] == 'F') {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		if (z[2] == 'D') {
			cout << "1";
		} else {
			cout << "0";
		}
	}

	return 0;
}