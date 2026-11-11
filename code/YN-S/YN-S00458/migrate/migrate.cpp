#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int w = 1; w <= t; w++) {
		long long n, d;
		cin >> n >> d;
		long long a[2000001] = {};
		for (long long i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int cha = abs(a[2] - a[1]);
		if (d < (2 * cha)) {
			cout << 0;
			continue;
		} else {
			long long b = d / cha;
		}
	}
	return 0;
}