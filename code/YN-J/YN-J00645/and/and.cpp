#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int max1;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		max1 = max(max1, a[i]);
	}

	if (k == 1) {
		cout << max1;
	}

	else  if (k == 2) {
		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				if (a[i]&a[j] > max1)
					max1 = a[i] & a[j];
			}
		}
	} else if (k == 3) {
		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				for (int m = j + 1; m <= n; m++) {

					if (a[i]&a[j]&a[m] > max1)
						max1 = a[i] & a[j] & a[m];
				}
			}
		}
	}

	cout << max1;
	return 0;
}