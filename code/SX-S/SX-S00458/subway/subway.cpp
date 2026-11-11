#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int c, n, m, d, q, w[N * N], mp[N][N], k[N], a[N][N], t[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if (j > 1)
				mp[j][j - 1] = 1, mp[j - 1][j] = 1;
		}
	}
	while (q--) {
		int x, y, ans = 0;
		cin >> x >> y;
		ans += w[x] + w[y];
		if (mp[x][y] == 1) {
			ans += t[x][y] + t[y][x];
			cout << ans << "\n";
		} else {
			int k = x;
			for (int i = 1; i <= n; i++) {
				if (mp[k][i] == 1) {
					ans += t[k][i] + t[i][k];
					k = i;
					continue;
				}
			}
			cout << ans << "\n";
		}
	}

	return 0;
}