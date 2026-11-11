#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, ans;
	string w, k;
	string x, y;
	char a[505][500005], t[505][500005];
	cin >> c >> n >> m >> d >> q;
	for (int v = 1; v <= m; v++) {
		cin >> w[v];

		for (int i = 1; i <= n; i++) {
			cin >> k[i];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= k[i]; j++) {
					cin >> a[i][j] >> t[i][j];
					cout << w[1] + t[i][j] + t[i + 1][j] + t[i][j + 1] + w[v] << w[1] + t[i][j] + t[i][j + 1] + w[v] << endl;
				}
			}
		}

	}
	for (int r = 1; r <= q; r++) {
		cin >> x[r] >> y[r];
	}
	return 0;
}