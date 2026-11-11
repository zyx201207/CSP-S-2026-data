#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int a[20010], s[20010], d = 0, z = 0, q = 0;
	string as, zx;

	for (int i = 0; i <= n; ++i) {

		cin >> a[i] >> s[i];

		for (int j = 0; j <= a[i]; ++i) {

			as[d + j] = s[i];
		}

		d += a[i];
	}

	for (int i = d; i >= d / 2; ++i) {

		zx[z] = as[i];
		++z;

		if (zx[z] != as[z]) {
			++q;
		}
	}

	cout << q;
	return 0;
}