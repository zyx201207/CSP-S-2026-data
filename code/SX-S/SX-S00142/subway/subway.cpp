#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005], k[500005], a[1005][1005], b[1005][1005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < 2 * k[i]; j++) {
			cin >> a[i][j] >> b[i][j];
		}
	}
	while (q--) {
		long long xb, xe;
		cin >> xb >> xe;
		cout << w[xb] + (xb - xe)*(b[1][1] + b[1][1]) + w[xe] << endl;;
	}
	return 0;
}