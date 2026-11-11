#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], ans = 1, gc;
bool flag = 1, flag_gc = 1;

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (i != 1 && a[i] != a[i - 1]) {
			flag = 0;
		}
	}

	sort(a + 1, a + 1 + n);

	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			flag_gc = 0;
			break;
		}
	}

	if (flag) {
		ans = n;
	} else if (flag_gc) {
		ans = 0;
		long long sum = 0;

		while (sum + gc <= m && ans + 1 <= n) {
			ans++;
			gc += 2;
			sum += gc;
		}
	} else {
		for (long long i = 1; i <= n; i++) {
			long long sum = 0;

			if (ans > i)
				break;

			for (int j = i - 1; j >= 1; j--) {
				long long cost = a[i] - a[j];

				if (sum + cost <= m) {
					ans = max(ans, i - j + 1);
					sum += cost;
				} else {
					break;
				}
			}
		}
	}

	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}