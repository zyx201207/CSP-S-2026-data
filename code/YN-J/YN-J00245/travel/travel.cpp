// c - j - c 2026 10 31 csp T1
#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
string e, f;

int main(void) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	e = b[0] + b[1], f = d[0] + d[1];
	if (a == c) {
		cout << 1;
		if (e == f) {
			cout << 1;
			if ((b[2] <= 'C' and d[2] <= 'C') or (b[2] > 'C' and d[2] > 'C')) {
				cout << 1;
				if (abs(int(b[2] - d[2])) <= 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else
		cout << "0000";
	return 0;
}