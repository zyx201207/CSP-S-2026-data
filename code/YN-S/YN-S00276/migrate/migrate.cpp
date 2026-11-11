#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;

	while (t--) {
		int n, d;
		int x[2000005];
		cin >> n >> d;

		for (int i = 0; i < n; i++) {

			cin >> x[i];

		}

		int cnt = 0;

		for (int j = n - 1; j >= 0; j--) {

			for (int i = 0; i < n; i++) {

				int sum = x[j] - x[i];

				if (sum % d == 0) {
					cnt++;
				}
			}
		}

		cout << cnt << '\n ';
	}

	return 0;
	fclose(stdin);
	fclose(stdout);
}