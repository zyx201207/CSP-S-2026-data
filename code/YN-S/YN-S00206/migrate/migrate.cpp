#include <bits/stdc++.h>
using namespace std;
long long c, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

	while (t--) {
		long long n, d, cnt = 0;
		cin >> n >> d;
		long long x[50005];

		for (long long i = 1; i <= n; i++) {

			cin >> x[i];
		}

		for (long long i = 1; i <= n; i++) {

			for (long long j = i + 1; j <= n; j++) {

				if (x[j] - x[i] > d && x[j] - x[i] <= d * (j - i - 1) && (j - i) % 2 == 1) {
					cnt++;
					break;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}