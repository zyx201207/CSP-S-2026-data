#include <bits/stdc++.h>
using namespace std;
int w[500005], k[505], t[505][500005], a[505][500005];
long long d[500005];
struct node {
	int id, v;
};
vector<node> g[500005];
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		int b;
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		bool f1 = 0, f2 = 0;
		cin >> x >> y;
		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= k[j]; l++) {
				if (a[j][l] == x) f1 = 1;
				if (a[j][l] == y) f2 = 1;
			}
			if (f1 && f2) {
				cout << w[x] + w[y] + t[j][x] + t[j][y] << '\n';
				continue;
			}
		}
	}
	return 0;
}