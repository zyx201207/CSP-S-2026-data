#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, d, ans = 0;
	cin >> n >> d;
	int a[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i += d) {
		if (a[i] + d + d / 2 == a[i - 1] + d + d)
			ans += 1;
	}
	cout << ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c1, t;
	cin >> c1 >> t;
	while (t--) {
		solve();
	}
	return 0;
}
