#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long n, a[N], ans = 0;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	for (long long i = 1; i <= n; i++)

		cin >> a[i] >> c[i];

	for (long long i = 1; i * 2 <= n; i++) {

		if (c[i] != c[n - i + 1]) {
			int m = n - i + 1;

			while (a[i] > 0) {
				if (c[i] != c[m - i + 1]) {
					ans += min(a[i], a[m - i + 1]);
					a[i] -= min(a[i], a[m - i + 1]);
					a[m - i + 1] -= min(a[i], a[m - i + 1]);

					if (a[i] > 0)
						c[m - i + 1] = c[i];
					else
						break;
				} else {
					a[i] -= min(a[i], a[m - i + 1]);
					a[m - i + 1] -= min(a[i], a[m - i + 1]);
				}

				m--;
			}
		} else {
			a[i] -= min(a[i], a[n - i + 1]);
			a[n - i + 1] -= min(a[i], a[n - i + 1]);

			if (a[i] > 0) {
				int m = n - i + 1;

				while (a[i] > 0) {
					m--;

					if (c[i] != c[m - i + 1]) {
						ans += min(a[i], a[m - i + 1]);
						a[i] -= min(a[i], a[m - i + 1]);
						a[m - i + 1] -= min(a[i], a[m - i + 1]);

						if (a[i] > 0)
							c[m - i + 1] = c[i];
						else
							break;
					} else {
						a[i] -= min(a[i], a[m - i + 1]);
						a[m - i + 1] -= min(a[i], a[m - i + 1]);
					}
				}
			}
		}
	}

	cout << ans << "\n";
	return 0;
}