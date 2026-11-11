#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, z1, z2;
	cin >> c1 >> z1 >> c2 >> z2;
	int s2 = (z2[0] - '0') * 10 + z2[1] - '0', s1 = (z1[0] - '0') * 10 + z1[1] - '0';

	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	if (s1 == s2) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}

	char a1 = z1[2], a2 = z2[2];

	if (a1 == 'A') {
		if (a2 == 'B') {
			cout << "11";
		} else if (a2 == 'C') {
			cout << "10";
		} else {
			cout << "00";

		}
	}

	else if (a1 == 'C') {
		if (a2 == 'B') {
			cout << "11";
		} else if (a2 == 'A') {
			cout << "10";
		} else {
			cout << "00";

		}
	}

	else if (a1 == 'B') {
		if (a2 == 'A') {
			cout << "11";
		} else if (a2 == 'C') {
			cout << "11";
		} else {
			cout << "00";

		}
	} else if (a1 == 'D') {
		if (a2 == 'F')
			cout << "11";
		else {
			cout << "00";

		}
	} else {
		if (a2 == 'D')
			cout << "11";
		else {
			cout << "00";

		}
	}

	return 0;
}