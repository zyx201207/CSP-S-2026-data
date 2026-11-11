#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] - c2[0] != 0) {
		cout << "0000";
		return 0;
	} else if (c1[1] - c2[1] != 0) {
		cout << "0000";
		return 0;
	} else {
		cout << 1;
	}
	if ((s1[0] - '0') != (s2[0] - '0')) {
		cout << "000";
		return 0;
	} else if ((s1[1] - '0') != (s2[1] - '0')) {
		cout << "000";
		return 0;
	} else {
		cout << 1;
	}
	if (s1[2] == 'C' && s2[2] == 'D') {
		cout << "00";
		return 0;
	} else if ((s1[2] - 'A') <= 2) {
		if ((s2[2] - 'A') <= 2) {
			cout << 1;
		}
	} else if (s1[2] - 'A' > 2) {
		if (s2[2] - 'A' > 2) {
			cout << 11;
			return 0;
		}
	} else {
		cout << "00";
		return 0;
	}
	if (abs(s1[2] - s2[2]) == 1) {
		cout << 1;
	} else {
		cout << "0";
	}
	return 0;
}