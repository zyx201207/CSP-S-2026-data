#include <bits/stdc++.h>
using namespace std;
int w[100010], k[500010], a[510][100010], t[510][100010], x[100010], y[100010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 0; i <= q; i++) {
		cin >> x[i] >> y[i];
	}



}