#include <bits/stdc++.h>
using namespace std;



long long a[50005] = {}, b[50005] = {},  c[5005] = {}, cnt = 0, sum = 0, f = 0, f2 = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, sum = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	for (int i = 1; i < n; i++) {

		if (a[n - i] < 0 && a[n - i + 1] > 0) {
			if (abs(abs(a[n - i + 1]) + abs(a[n - i])) < m) {
				if (abs(abs(a[n - i + 1]) + abs(a[n - i])) % abs(abs(a[n - i]) + abs(a[n - i - 1])) == 0) {
					f++;
				}
				long long m3 = m;
				m3 -= m3;
				b[sum] = abs(abs(a[n - i + 1]) + abs(a[n - i]));
			}

		} else if (a[n - i + 1] < 0 && a[n - i] > 0) {
			if (abs(abs(a[n - i + 1]) + abs(a[n - i])) < m) {
				if (abs(abs(a[n - i + 1]) + abs(a[n - i])) % abs(abs(a[n - i]) + abs(a[n - i - 1])) == 0) {
					f++;

				}
				long long m2 = m;
				m2 -= abs(abs(a[n - i + 1]) + abs(a[n - i]));
				b[sum] = abs(a[n - i + 1]) + abs(a[n - i]);
			}

		} else if (a[n - i + 1] > 0 && a[n - i] > 0) {
			if (a[n - i + 1] - a[n - i] < m) {
				if (a[n - i + 1] - a[n - i] % a[n - i] - a[n - i - 1]) {
					f++;
				}
				long long m1 = m;
				m1 -= a[n - i + 1] - a[n - i];
				b[sum] = a[n - i + 1] - a[n - i];
			}

		}
		sum++;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (b[i] == b[j]) {
				c[i]++;
			}
		}
	}
	sort(c, c + n);
	for (int i = n; i >= 1; i--) {
		if (c[i] == 0) {
			continue;
		} else {
			if (f > 1) {
				cout << c[i] + 1;
				return 0;
			}
			cout << c[i] + f;
			return 0;
		}
	}
}