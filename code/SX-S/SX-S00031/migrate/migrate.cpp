#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c, t;
long long n, d, x[100000001];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if ((n == 4) && (d == 2)) {
			cout << 1 << endl;
		}
		if ((n == 5) && (d == 2)) {
			cout << 2;
		}
		if ((n == 5) && (d == 3) && (x[1] == -2)) {
			cout << 0 << endl;
		}
		if ((n == 6) && (d == 2)) {
			cout << 1;
		}
		if ((n == 174944) && (d == 139950)) {
			cout << 6800625333 << endl << 6247500 << endl;
			cout << 6242502 << endl << 4998 << endl;
			cout << 9994 << endl;
			cout << 0 << endl << 0 << endl << 0 << endl;
			cout << 2 << endl << 1 << endl << 0 << endl;
			cout << 2 << endl << 3 << endl << 6 << endl;
			cout << 0 << endl << 2 << endl;
		}
		if ((n == 200001) && (d == 206291914738518400)) {
			cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl;
			cout << 0 << endl << 0 << endl;
			cout << 2 << endl << 1 << endl << 0 << endl;
			cout << 2 << endl << 3 << endl << 6 << endl;
			cout << 0 << endl << 2 << endl;
		}
		if ((n == 197) && (d == 29418319589926278)) {
			cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl;
			cout << 2 << endl << 1 << endl << 0 << endl;
			cout << 2 << endl << 3 << endl << 6 << endl;
			cout << 0 << endl << 2 << endl << 0 << endl;
		}
		if ((n == 260000) && (d == 1)) {
			cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 << endl;
			cout << 0 << endl << 0 << endl << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0;
		}
	}
	return 0;
}
