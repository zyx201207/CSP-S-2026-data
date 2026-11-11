#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel5.in", "i", stdin);
	freopen("travel5.out", "w", stdout);
	string a, s, d, f;
	cin >> a >> s >> d >> f;
	if (a == d) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (s[0] == f[0] && s[1] == s[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (s[2] == 'A' || s[2] == 'B' || s[2] == 'C' && f[2] == 'A' || f[2] == 'B' || f[2] == 'C') {
		cout << "1";
	} else if (s[2] == 'D' || s[2] == 'F' && f[2] == 'D' || f[2] == 'F') {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (s[2] + 1 == f[2] || s[2] - 1 == f[2]) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;

}