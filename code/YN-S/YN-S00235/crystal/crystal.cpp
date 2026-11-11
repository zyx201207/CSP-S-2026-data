#include <bits/stdc++.h>
using namespace std;
long long a[120000005], b[120000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, avg = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		avg += a[i];
	}

	if (m == 0) {
		int ans = 0;
		sort(a + 1, a + 1 + n);

		for (int i = 1; i <= n; i++) {

			if (a[i] != a[i + 1]) {
				cout << ans + 1;
				return 0;
			}

			ans++;
		}
	}

	avg /= n;

	for (int i = 1; i <= n; i++) {

		b[i] = abs(a[i] - avg);
	}

	int ans = 0;
	sort(b + 1, b + 1 + n);

	for (int i = 1; i <= n; i++) {

		if (m - b[i] >= 0) {
			ans++;
			m -= b[i];
		} else {
			break;
		}
	}

	cout << ans;
	return 0;
}
