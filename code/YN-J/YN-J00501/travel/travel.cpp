#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ss1, s1, ss2, s2;
	cin >> ss1 >> s1 >> ss2 >> s2;
	if (ss1 == ss2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
		cout << 1;
	} else if ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	char a = s1[2], b = s2[2];
	if ((a == 'D' && b == 'C') || (a == 'C' && b == 'D')) {
		cout << 0;
	} else if ((a + 1 == b || a - 1 == b)) {
		cout << 1;
	} else if ((a == 'F' && b == 'D') || (a == 'D' && b == 'F')) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}