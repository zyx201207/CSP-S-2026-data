#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, x, y = 0, z = 0;
	cin >> n >> m;
	int a(100000);
	int b(100000);

	for (int i = 0; i <= n; i++) {

		cin >> x;

		if (i == 0) {
			z = x;
		}

		y = max(x, y);
		z = min(x, z);
	}

	if (m == 1) {
		cout << y;
	} else if (m == n) {
		cout << z;
	} else if (m == 2) {
		cout << y - 1;
	} else if (m == n - 1) {
		cout << z + 1;
	} else {
		cout << x;
	}

	return 0;
}