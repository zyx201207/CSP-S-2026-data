#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1 = 02, c2 = 02;
	string b1, b2;
	cin >> c1 >> b1 >> c2 >> b2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
	}
	if (b1[0] == b2[0] && b1[1] == b2[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((65 <= b1[2] && b1[2] <= 67 && 65 <= b2[2] && b2[2] <= 67) || (68 <= b1[2] && b1[2] <= 70 && 68 <= b2[2]
	        && b2[2] <= 70)) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (b1[2] + 1 == b2[2] || b1[2] - 1 == b2[2]) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}