#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500010];
int c[500010];
int p[500010];
bool f = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		c[i] = a[i] - a[i - 1];

		if (i > 2 && c[i] != c[i - 1])
			f = 1;
	}

	if (!f) {
		int l = 1, r = n;

		while (l < r) {
			int mid = (l + r) / 2;
			int ans = (mid * (mid + 1) * c[3]) / 2;

			if (ans <= m) {
				l = mid + 1;
			} else if (ans > m ) {
				r = mid;
			}
		}

		cout << l;
	} else {
		int ans = 0;

		for (int i = 1; i <= n; i++) {

			p[i] += a[i];
		}

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {

				int cnt = a[i] * j;

				for (int k = i - j + 1; k <= i; k++) {

					int sum = cnt - (p[k + j - 1] - p[k - 1]);

					if (sum <= m)
						ans = max(ans, j);
				}
			}
		}

		cout << ans;
	}

	return 0;
}