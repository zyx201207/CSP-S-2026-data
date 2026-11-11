#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	int n, d;
	int a[10003];
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		if (n <= 2) {
			cout << 0;
		}
	}
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= n; j++) {
			int sum = 0;
			int s = 0;
			if (a[j + 1] - a[j] <= d) {
				sum = a[j + 1] - a[j];
			}
			sum += d;
			if (sum + 1 == a[j + 3]) {
				sum++;
				if (a[j + 2] - a[j] <= d) {
					s = a[j + 2] - a[j];
					s++;
					if (s + d == a[j + 3]) {
						if (sum == s) {
							ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}