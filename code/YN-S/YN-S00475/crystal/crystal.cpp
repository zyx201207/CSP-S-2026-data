#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, a[500086], ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int sum = m, x = 0, y;
		for (int j = 0; j <= i; j++) {
			sum += a[j];
			y = a[i];
		}
		if (sum % (i + 1) == 0 && sum / (i + 1) >= y) {
			x = i + 1;

		}
		ans = max(x, ans);
	}
	cout << ans;
	return 0;
}
