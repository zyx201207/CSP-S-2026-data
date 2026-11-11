#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, lc[507][507], w[504], k, a1, t1, a2, t2;
int a[28], t[28];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		lc[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			lc[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; j++)
			for (int z = 1; z <= k; z++) {
				lc[a[j]][a[z]] = t[j] + t[z];
				lc[a[z]][a[j]] = t[j] + t[z];
			}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int z = 1; z <= m; z++) {
				lc[i][z] = min(lc[i][z], lc[i][j] + lc[j][z]);
			}
		}
	}
	int ks, js;
	for (int i = 1; i <= q; i++) {
		cin >> ks >> js;
		cout << w[ks] + lc[ks][js] + w[js] << endl;
	}
}