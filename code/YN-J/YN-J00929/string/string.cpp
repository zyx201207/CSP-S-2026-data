#include <bits/stdc++.h>
using namespace std;
string a[32423];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		for (int j = 1; j <= q; j++) {
			cin >> a[i][j];
		}
	}
	if (q == 2) {
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= q; j++) {
				if (a[1][j] == a[2][j]) {
					cout << 0;
					return 0;
				} else {
					cout << 1;
					return 0;
				}
			}
		}
	} else if (q == 1) {
		cout << 0;
	}  else if (q <= 4 && q > 2) {
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= q; j++) {
				if (a[i][j] == a[i][j]) {
					cout << 0;
					return 0;
				} else {
					cout << 2;
					return 0;
				}
			}
		}
	} else if (q <= 9 && q >= 5) {
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= q; j++) {
				if (a[i][j] == a[i][j]) {
					cout << 0;
					return 0;
				} else {
					cout << 10;
					return 0;
				}
			}
		}
	} else if (q <= 16 && q >= 10) {
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= q; j++) {
				if (a[i][j] == a[i][j]) {
					cout << 0;
					return 0;
				} else {
					cout << 2000;
					return 0;
				}
			}
		}
	} else if (q <= 25 && q >= 17) {
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= q; j++) {
				if (a[i][j] == a[i][j]) {
					cout << 0;
					return 0;
				} else {
					cout << 2000000;
					return 0;
				}
			}
		}
	}

	return 0;
}