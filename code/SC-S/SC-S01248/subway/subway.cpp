#include<bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 10;
long long n, ans, c, m, d, q, g[N][N], w[N], t[N], a[N], k, x, y, dis[N * 20];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(g, 0x3f, sizeof(g));
	if (c <= 11) {
		for (int i = 1; i <= m; i++) cin >> w[i], g[i][i] = 0;
		while (n--) {
			cin >> k;
			for (int i = 1; i <= k; i++) {
				cin >> a[i] >> t[i];
			}
			for (int i = 1; i <= k; i++) for (int j = i + 1; j <= k; j++) {
					g[a[i]][a[j]] = g[a[j]][a[i]] = t[i] + t[j];
				}
		}
		for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) for (int k = 1; k <= m; k++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		while (q--) {
			cin >> x >> y;
			cout << g[x][y] + w[x] + w[y] << "\n";
		}
	}
	return 0;
}