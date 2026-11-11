#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long x[2000005], d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int q = 0; q < t; q++) {
		cin >> n >> d;
		for (int i = 0; i < 3; i++) {
			cin >> x[i];
		}
		long long dx = x[1] - x[0];
		long long l = d / dx;
		long long ans = n - 2 * l + 1;
		cout << ans;
	}
	return 0;
}