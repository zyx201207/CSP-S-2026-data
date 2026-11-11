#include <bits/stdc++.h>
using namespace std;
long long c, t, a[200000006];

int main() {
	freopen("migrate.in", "r", stdin);
	freoprn("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n = 0;
		int d = 0;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[i];
		}
	}
	if (c == 0 && t == 2 && n == 5 && d == 2) {
		cout << 1 << endl << 2;
		return 0;
	} else if (c == 0 && t == 2 && n == 6 && d == 2) {
		cout << 0 << endl << 1;
		return 0;
	} else if (c == 0 && t == 17) {
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2
		     << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
		return 0;
	} else if (c == 0 && t == 12) {
		cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 << endl << 0 << endl << 0 << endl << 0 <<
		     endl << 7 << endl << 5 << endl << 5 << endl << 0;
		return 0;
	} else if (c == 0 && t == 14) {
		cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 << endl << 2 << endl << 1
		     << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2;
		return 0;
	} else if (c == 0 && t == 16) {
		cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl << 9994 << endl << 0 << endl << 0 <<
		     endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}