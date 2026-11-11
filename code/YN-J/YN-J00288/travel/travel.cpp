#include <bits/stdc++.h>
using namespace std;
char a[5], b[5], c[5], d[5];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> a[0] >> a[1] >> b[0] >> b[1] >> b[2] >> c[0] >> c[1] >> d[0] >> d[1] >> d[2];
	if (a[0] == c[0] && a[1] == c[1]) {
		cout << 1;
		if (b[1] == d[1] && b[0] == d[0]) {
			cout << 1;
			if (b[2] == 'A') {
				if (d[2] == 'B') {
					cout << "11";
					return 0;
				} else if (d[2] == 'C') {
					cout << "10";
					return 0;
				} else {
					cout << "00";
					return 0;
				}
			} else if (b[2] == 'B') {
				if (d[2] == 'A') {
					cout << "11";
				} else if (d[2] == 'C') {
					cout << "11";
				} else {
					cout << "00";
				}
			} else if (b[2] == 'C') {
				if (d[2] == 'A') {
					cout << "10";
				} else if (d[2] == 'B') {
					cout << "11";
				} else {
					cout << "00";
				}
			} else if (b[2] == 'D') {
				if (d[2] == 'F') {
					cout << "11";
				} else {
					cout << "00";
				}
			} else {
				if (d[2] == 'D') {
					cout << "11";
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
