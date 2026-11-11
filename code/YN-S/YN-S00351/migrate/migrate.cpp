#include <bits/stdc++.h>
using namespace std;
long long x[2000050], pre[2000050];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c, t, n, d, s = 0, idx, zd = INT_MIN, zx = INT_MAX;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[i];
		}
		sort(x + 1, x + n + 1);
		for (int j = 2; j <= n; j++) {
			pre[j] = pre[j - 1] + x[j] - x[j - 1];
			zd = max(pre[i], zd);
			zx = min(pre[i], zx);
		}
		if (d > pre[n] || zx > d || zd < d) {
			cout << '0' << endl;
			continue;
		}
		for (int r = 1; r <= n - 1; r++) {
			for (int j = 1; j <= n; j++) {
				if (pre[j] - pre[idx] > 2 * d || j == n) {
					idx = j - 1;
					s++;
				}
			}

		}
		cout << s << endl;
	}

	return 0;
}