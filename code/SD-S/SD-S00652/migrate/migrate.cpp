#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 7;
int x[N];
int n, d;
void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	bool ok = false;
	for (int i = 2; i < n; i++) {
		if (x[i] - x[i - 1] == x[i + 1] - x[i]) {
			ok = true;
		} else {
			ok = false;
			break;
		}
	}
	if (ok) {
		int d1 = x[n] - x[n - 1];
		int p = (d + d1 - 1) / d1;
		cout << max(0LL, n - p * 2 + 1) << '\n';
	} else {
		cout << 1 << '\n';
	}
	return ;
}
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
