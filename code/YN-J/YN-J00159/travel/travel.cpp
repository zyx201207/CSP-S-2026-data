#include <bits/stdc++.h>
using namespace std;

string a1, a2, b1, b2;
char s1, s2;
bool a, b;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a1 >> a2 >> b1 >> b2;

	if (a1.substr(0, 2) != b1.substr(0, 2)) {
		cout << "0000";
		return 0;
	} else {
		cout << 1;
	}

	if (a2.substr(0, 2) != b2.substr(0, 2)) {
		cout << "000";
		return 0;
	} else {
		cout << 1;
	}

	s1 = a2[2], s2 = b2[2];

	if (s1 == 'A' || s1 == 'B' || s1 == 'C') {
		a = true;
	}

	if (s2 == 'A' || s2 == 'B' || s2 == 'C') {
		b = true;
	}

	if (a == b) {
		cout << "00";
		return 0;
	} else {
		cout << 1;
	}

	if (fabs(s1 - s2) != 1) {
		cout << "0";
		return 0;
	} else {
		cout << 1;
	}

	return 0;
}
