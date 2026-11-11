#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int c, t, n, d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];

			if (x[j + 1] - x[j] <= d && x[j] - x[j] - x[j] <= d && x[j + 2] - x[j] <= d) {
				sum++;
			}

		}
		cout << sum;

	}

	freopen("migrate.out", "w", stdout);
	return 0;
}