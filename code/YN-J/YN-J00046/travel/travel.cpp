#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int a1, a2, a3, b1, b2, b3;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	a1 = (a[0] - '0') * 10 + a[1] - '0';
	a2 = (b[0] - '0' ) * 10 + b[1] - '0';
	a3 = b[2] - 'A' + 1;
	b1 = (c[0] - '0') * 10 + c[1] - '0';
	b2 = (d[0] - '0' ) * 10 + d[1] - '0';
	b3 = d[2] - 'A' + 1;
	if (a1 == b1) {
		cout << '1';
		if (a2 == b2) {
			cout << '1';
			if (a3 <= 3 && b3 <= 3) {
				cout << '1';
				if (a3 == 2 || b3 == 2) {
					cout << '1';
				} else {
					cout << '0';
				}
			} else if (a3 > 3 && b3 > 3) {
				cout << "11";
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}