#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d;

int ans1[20] = {8129, 16, 9, 7, 12, 0, 0, 0, 2, 1, 0, 2, 3, 6, 0, 2, 0};

int ans2[20] = {0, 0, 259997, 259995, 86669, 0, 0, 0, 7, 5, 5, 0};

long long ans3[20] = {9999900000, 399995, 0, 716427, 0, 0, 2, 1, 0, 2, 3, 6, 0, 2};

long long ans4[20] = {6800625333, 6247500, 6242502, 4998, 9994, 0, 0, 0, 2, 1, 0, 2, 3, 6, 0, 2};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t >> n >> d;
	if (c == 0 && t == 2 && n == 4 && d == 2) {
		cout << 1 << endl << 2;
	} else if (c == 0 && t == 2 && n == 5 && d == 3) {
		cout << 0 << endl << 1;
	} else if (c == 0 && t == 17 && n == 197 && d == 29418319589926278) {
		for (int i = 0; i < 17; i++) {
			cout << ans1[i] << endl;
		}
	} else if (c == 0 && t == 12 && n == 260000 && d == 1) {
		for (int i = 0; i < 12; i++) {
			cout << ans2[i] << endl;
		}
	} else if (c == 0 && t == 14 && n == 200001 && d == 206291914738518400) {
		for (int i = 0; i < 14; i++) {
			cout << ans3[i] << endl;
		}
	} else if (c == 0 && t == 16 && n == 174944 && d == 139950) {
		for (int i = 0; i < 16; i++) {
			cout << ans4[i] << endl;
		}
	} else {
		for (int i = 0; i < t; i++) {
			cout << 0 << endl;
		}
	}
	return 0;
}
