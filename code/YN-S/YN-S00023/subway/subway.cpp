#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, k;



int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	long long w[m + 5], k[n + 5], a[n + 5], t[n + 5], x[q + 5], y[q + 5];

	w[0] = 0;
	k[0] = 0;
	a[0] = 0;
	x[0] = 0;
	y[0] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i] ;
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i] >> t[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	while (q--) {
		long long time = 0;
		for (long long i = 1; i <= n; i++) {
			bool x1 = 0, y1 = 0;
			if (x[q] == a[i]) {
				time += w[x[q]] + t[i];
				x1 = 1;
			}
			if (y[q] == a[i]) {
				time += w[y[q]] + t[i];
				y1 = 1;
			}
			if (x1 && y1)
				cout << time;
		}

		return 0;
	}
}