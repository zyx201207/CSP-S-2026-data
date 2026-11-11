#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[20010], c[20010], b[20010];

signed main() {
	int k = 1;
	int n, m;
	cin >> n >> m;

	if (m == 1) {
		int maxx = 0;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
			maxx = max(maxx, a[i]);
		}

		cout << maxx;
		return 0;
	}

	if (m == n) {
		cin >> a[1];
		int ans = a[1];

		for (int i = 2; i <= n; i++) {

			cin >> a[i];
			ans = ans & a[i];
		}

		cout << ans;
		return 0;
	}

	if (m = 2) {
		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		int maxx = 0;

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				maxx = max(maxx, a[i] & a[j]);
			}
		}

		cout << maxx;
		return 0;
	}

	int maxx = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		maxx = max(maxx, a[i]);
	}

	for (int i = 1; i <= n; i++) {

		if (!b[a[i]]) {
			c[k++] = a[i];
		}

		b[a[i]]++;
	}

	if (n - b[0] < m) {
		cout << 0;
		return 0;
	}

	return 0;
}