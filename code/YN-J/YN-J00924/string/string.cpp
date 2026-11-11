#include <bits/stdc++.h>
using namespace std;

int n, dan;
string s, yb1, yb2;
int zs;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {

		int a;

		char b;

		cin >> a >> b;

		zs += a;

		for (int j = 1; j <= a; j++) {

			s += b;
		}
	}

	int ans = zs / 2;

	if (zs % 2 == 0) {
		for (int i = 0; i < ans; i++) {

			yb1 += s[i];
		}

		for (int i = zs - 1; i >= ans; i--) {

			yb2 += s[i];
		}
	} else {
		ans++;

		for (int i = 0; i < ans; i++) {

			yb1 += s[i];
		}

		for (int i = zs - 1; i >= ans - 1; i--) {

			yb2 += s[i];
		}
	}

	for (int i = 0; i < ans; i++) {

		if (yb1[i] != yb2[i]) {
			dan++;
		}
	}

	cout << dan;

	return 0;
}