#include <bits/stdc++.h>
using namespace std;
string c[5], s[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string t;
	cin >> c[1] >> s[1] >> c[2] >> s[2];

	string n, m;
	n = s[1][0] + s[1][1];
	m = s[2][0] + s[2][1];
	bool a = 1;
	if (c[1] == c[2]) {
		t += '1';
	} else {
		t += '0';
		a = 0;
	}
	if (m == n && a == 1) {
		t += '1';
	} else {
		t += '0';
		a = 0;
	}
	if ((s[1][2] >= 'A' && s[1][2] <= 'C') && (s[2][2] >= 'A' && s[2][2] <= 'C') && a == 1) {
		t += '1';
	} else if ((s[1][2] >= 'D' && s[1][2] <= 'E') && (s[2][2] >= 'D' && s[2][2] <= 'E') && a == 1) {
		t += '1';
	} else {
		t += '0';
		a = 0;
	}
	if (s[1][2] > s[2][2] && (char)(s[1][2] - 1) == s[2][2] && a == 1) {
		t += '1';
	} else if (s[1][2] < s[2][2] && (char)(s[1][2] + 1) == s[2][2] && a == 1) {
		t += '1';
	} else {
		t += '0';
	}

	cout << t;

	return 0;
}
