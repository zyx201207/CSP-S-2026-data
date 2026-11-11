#include <bits/stdc++.h>
using namespace std;
int w[500005], k[500005], a[505][500005], t[505][500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int ti = 0;
		int x, y;
		cin >> x >> y;
		ti += w[x] + w[y];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				if (a[i][j] == x) {
					ti += t[i][j];
					if (a[i][k[i] - j] == y) {
						x = a[i][j];
					} else if (a[k[i] - i][j] == a[i][j]) {
						x = a[i][j];
					} else {
						x = a[i][j - 1];
					}
				}
			}
		}
		if (x == y) {
			cout << ti << endl;
			continue;
		}
		q++;
	}
	return 0;
}
