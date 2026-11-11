#include <iostream>
#include <cmath>
using namespace std;
string a, b, c, d, x, y;
char m, n;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << '1';
	} else {
		cout << "0000";
		return 0;
	}
	for (int e = 0; e < 2; e++) {
		x += b[e];
		y += d[e];
	}
	if (x == y) {
		cout << '1';
	} else {
		cout << "000";
		return 0;
	}
	m = b[2];
	n = d[2];
	if (m >= 'D' && n >= 'D') {
		cout << "11";
	} else if ((m >= 'D' && n < 'D') || (m <= 'D' && n >= 'D')) {
		cout << "00";
	} else {
		if (abs(int(m) - int(n)) == 1) {
			cout << "11";
		} else {
			cout << "10";
		}
	}
	return 0;
}