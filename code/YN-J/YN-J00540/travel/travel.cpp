#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (b[2] == 'F')
		b[2] = 'E';
	if (d[2] == 'F')
		d[2] = 'E';
	if (a != c) {
		cout << "0000";
		return 0;
	}
	cout << '1';
	if (b[0] != d[0] || b[1] != d[1]) {
		cout << "000";
		return 0;
	}
	cout << '1';
	if ((b[2] > 'C' && d[2] < 'D') || (d[2] > 'C' && b[2] < 'D')) {
		cout << "00";
		return 0;
	}
	cout << '1';
	if ((b[2] == d[2] - 1) || (d[2] == b[2] - 1)) {
		cout << '1';
		return 0;
	}
	cout << '0';

	return 0;
}