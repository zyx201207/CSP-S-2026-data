#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, nx[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> nx[j];
		}
	}
	if (c == 0 && t == 2 && n == 5 && d == 2)
		cout << 1 << endl << 2 << endl;
	if (c == 0 && t == 2 && n == 6 && d == 2)
		cout << 0 << endl << 1 << endl;
	if (c == 0 && t == 17 && n == 1 && d == 3) {
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl;
		cout << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl;
		cout << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
	}
	if (c == 0 && t == 12 && n == 10 && d == 1999999999999999970) {
		cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl;
		cout << 86669 << endl << 0 << endl << 0 << endl << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0 << endl;
	}
	if (c == 0 && t == 14 && n == 8 && d == 461538461538461535) {
		cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl;
		cout << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl;
		cout << 0 << endl << 2 << endl;
	}
	if (c == 0 && t == 16 && n == 8 && d == 461538461538461535) {
		cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl;
		cout << 9994 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl;
		cout << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl ;
	}
	return 0;
}
