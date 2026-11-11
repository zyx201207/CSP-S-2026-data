#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	char f, e;
	int h = 0, j = 0;
	cin >> a >> b >> c >> d;
	f = b[2];
	e = d[2];
	if (a[0] * 10 + a[1] == c[0] * 10 + c[1]) {
		cout << "1";
		if (b[0] * 10 + b[1] == d[0] * 10 + d[1] ) {
			cout << "1";

			if (f == 65 || f == 66 || f == 67) {
				h++;
			} else {
				j++;
			}
			if (e == 65 || e == 66 || e == 67) {
				h++;
			} else {
				j++;
			}
			if (h == 2 || j == 3) {
				cout << "1";
				if (f + 1 == e || f - 1 == e) {
					cout << "1";
				} else {
					cout << "0";
				}

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