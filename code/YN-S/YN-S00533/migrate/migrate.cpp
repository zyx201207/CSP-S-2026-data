#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long c, t, n, d, ans;
long long a[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];
		}

		for (int i = 1; i <= n / 2; i++) {

			if ((n - i) % d > 0) {
				bool flag = 0;

				for (int j = 1; j <= n; j++) {

					if (a[j] == (n - i) % d) {
						flag = 1;
					}
				}

				for (int j = 1; j <= n; j++) {

					if (a[j] == n - (n - i) % d && flag == 1) {
						ans++;
					}
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}