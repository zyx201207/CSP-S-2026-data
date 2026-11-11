#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p, w[500010], k[550], a[2500][2500], t[2500][2500], q, x[100050], y[100050], sum[2500];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];

	}
	sum[0] = 0, sum[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= 2 * (k[i]); j++) {
			cin >> a[i][j] >> t[i][j];
			sum[i + 1] = sum[i - 1] + t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		int ans = w[x[i]] + w[y[i]] + sum[y[i]] - sum[x[i]];
		cout << ans << endl;
	}
	return 0;
}