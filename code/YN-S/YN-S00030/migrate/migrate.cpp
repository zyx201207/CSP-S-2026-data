#include <bits/stdc++.h>
using namespace std;

long long c, t;
long long n[20], d[20], ans1[20], ans[20];
long long x[20][2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (long long i = 1; i <= t; i++) {
		cin >> n[i] >> d[i];
		for (long long y = 1; y <= n[i]; y++) {
			cin >> x[i][y];
		}
	}
	for (long long i = 1; i <= t; i++) {
		for (long long y = n[i]; y >= 1; y--) {
			for (long long j = y - 2; j >= 1; j--) {
				for (long long k = j + 1; k < y; k++) {
					if (x[i][y] - x[i][k] <= d[i] && x[i][k] - x[i][j] <= d[i] && x[i][y] - x[i][j] > d[i]) {
						ans1[i]++;
					}
				}
				if (ans1[i] == 2) {
					ans[i]++;
				}
				ans1[i] = 0;
			}
		}
	}
	for (long long i = 1; i <= t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}