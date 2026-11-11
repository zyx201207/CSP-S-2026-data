#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, max = -1;
	cin >> n >> m;
	int a[n];

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	if (m == 1) {
		sort(a, a + n);
		cout << a[n - 1];
	}

	if (m == 2) {
		for (int i = 0; i < n; i++) {

			for (int j = i; j < n; j++) {

				if (a[i]&a[j] > max) {
					max = a[i] & a[j];
				}
			}
		}

		cout << max;
	}

	if (m == 3) {
		for (int i = 0; i < n; i++) {

			for (int j = i; j < n; j++) {

				for (int k = j; k < n; k++) {

					if (a[i]&a[j]&a[k] > max) {
						max = a[i] & a[j] & a[k];
					}
				}
			}
		}

		cout << max;
	}

	return 0;

}
