#include <bits/stdc++.h>
using namespace std;

void fre() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
}
string a, b, c, d;

signed main() {
	fre();
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << 1;
			if (b[2] >= 'D') {
				if (d[2] >= 'D') {
					cout << "11";
				} else {
					cout << "00";
				}
			} else {
				if (d[2] < 'D') {
					cout << 1;
					if (b[2] == 'A') {
						if (d[2] == 'B') {
							cout << 1;
						} else {
							cout << 0;
						}
					} else if (b[2] == 'B') {
						cout << 1;
					} else if (b[2] == 'C') {
						if (d[2] == 'B') {
							cout << 1;
						} else {
							cout << 0;
						}
					}
				} else {
					cout << "00";
				}
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
