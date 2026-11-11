#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[500005];

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	int d = 0;
	int g = a[n / 2] + 1;

	for (int i = n / 2; i >= 1; i--) {

		if (a[i] < a[i + 1]) {
			a[i] += a[i + 1] - a[i];
			m -= a[i + 1] - a[i];
		}

		if (m == 0) {
			break;
		}
	}

	int f = n;

	while (n) {
		int i = 1;

		if (a[i] == a[i + 1] ) {
			d++;
		}

		i++;
		n--;
	}

	cout << d - f / 2;
	return 0;
}