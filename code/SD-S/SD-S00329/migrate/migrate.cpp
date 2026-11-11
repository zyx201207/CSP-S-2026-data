#include <bits/stdc++.h>

using namespace std;
int c, t;

const int N = 2e6 + 10;
long long n, d;
long long a[N];
void solve(int c) {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (c == 11 || c == 12) {
		long long ch = a[2] - a[1], ans = 0;
		if (d <= ch) {
			cout << "0\n";
			return;
		}
		d /= ch;
		for (int i = 1; i <= n - d * 2 + 1; ++i) {
			ans++;
		}
		cout << ans << "\n";
	} else if (c == 13 || c == 14) {
		cout << n / 2 - 1 << "\n";
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve(c);
	}
	return 0;
}

