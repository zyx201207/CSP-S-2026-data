#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[520], k[520], a[520][500010], t[520][500010], ans, l, r;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		ans += w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			ans += t[i][j];
		}
	}
	while (q--) {
		cin >> l >> r;
		cout << ans << endl;
	}
	return 0;
}
