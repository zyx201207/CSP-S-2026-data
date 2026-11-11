#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int m, n;
	int a[n], b[m] = {}, c[m] = {};

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		c[m] = {};

		for (int j = i; j < n; j++) {

			for (int k = j - 1; k >= i; k--) {

				if (a[j] == a[k]) {
					for (int h = k + 1; h < j; h++) {

						c[a[h]] = 0;
					}
				}
			}

			c[a[j]] = 1;
		}

		for (int l = 0; l < m; l++) {

			if (c[i] > 0)
				b[i] += c[i];
		}
	}

	for (int i = 0; i < m; i++) {

		cout << b[i] << " ";
	}

	return 0;
}