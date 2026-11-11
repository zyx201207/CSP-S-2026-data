#include <bits/stdc++.h>
using namespace std;

bool tc(string a, string b) {
	if ((a[2] == 'A' || a[2] == 'B' || a[2] == 'C') && (b[2] == 'A' || b[2] == 'B' || b[2] == 'C')) {
		return 1;
	} else if ((a[2] == 'D' || a[2] == 'F') && (b[2] == 'D' || b[2] == 'F')) {
		return 1;
	} else
		return 0;
}
string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool flag = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (flag == 1 && (s2[0] == s1[0] && s2[1] == s1[1])) {
		cout << 1;

	} else {
		cout << 0;
		flag = 0;
	}
	if (flag == 1 && tc(s1, s2)) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if (flag && !((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}