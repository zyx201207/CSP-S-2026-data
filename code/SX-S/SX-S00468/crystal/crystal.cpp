#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, max = 0;
	cin >> n >> m;
	if (n > 250000) {
		int a[500000];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		for (int i = n - 1; i > 0; i--) {
			long long s = 0;
			for (int j = i - 1; j >= 0; j--) {
				s += a[i] - a[j];
				if (s == m) {
					if (max < i - j + 1) {
						max = i - j + 1;
					}
					break;
				}
				if (s > m) {
					if (max < i - j) {
						max = i - j;
					}
					break;
				}
			}
		}
		cout << max;
	}
	if (n <= 250000) {
		long long a[250000];

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		for (int i = n - 1; i > 0; i--) {
			long long s = 0;
			for (int j = i - 1; j >= 0; j--) {
				s += a[i] - a[j];
				if (s == m) {
					if (max < i - j + 1) {
						max = i - j + 1;
					}
					break;
				}
				if (s > m) {
					if (max < i - j) {
						max = i - j;
					}
					break;
				}
			}
		}
		cout << max;
	}

	return 0;
}
