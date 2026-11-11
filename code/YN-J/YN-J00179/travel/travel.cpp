#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	char x, y;
	cin >> a >> c >> x >> b >> d >> y;
	if (a == b) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (c == d) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if ((('A' <= x <= 'C') && ('A' <= y <= 'C') || (('D' <= x <= 'F')) &&  ('D' <= y <= 'F'))) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (x >= 'D') {
		cout << "1";
	} else {
		if (x - y == 1 | -1) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	return 0;
}