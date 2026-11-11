#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, c, b, d;
	cin >> a >> b >> c >> d;
	if (a[2] == 1 || c[2] == 1) {
		cout << "0000";
		return 0;
	}
	if (a[1] == 1 && a[2] == 6) {
		cout << "0000";
		return 0;
	}
	if (c[1] == 1 && c[2] == 1) {
		cout << "0000";
		return 0;
	}
	if (a == c) {
		cout << "1";
		if (b[0] != d[0]) {
			cout << "000";
			return 0;
		} else if (b[1] != d[1]) {
			cout << "000";
			return 0;
		} else {
			cout << "1";
		}
		if (b[2] == 'C' && d[2] == 'D') {
			cout << "00";
			return 0;
		}
		cout << "1";
		if ( b[2] + 1 != d[2] && b[2] - 1 != d[2]) {
			cout << "0";
			return 0;
		}
		cout << "1";
	} else {
		cout << "0000";
	}
	return 0;
}
