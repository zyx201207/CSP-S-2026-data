#include <bits/stdc++.h>
using namespace std;

int c, t;
long long n, d, a[100000005], dp[100000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	a[0] = 10000000000;
	for (int i = 0; i < t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		long long e = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] - d == a[j - d] && (a[j + 1] - a[j]) <= d && a[j + 1] > a[j]) {
				e++;
			}
		}
		if (d >= 3) {
			e--;
		}
		cout << e << endl;
	}

	return 0;
}
