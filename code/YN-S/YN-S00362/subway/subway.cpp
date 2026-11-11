#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 10;
int c, n, m, d, q, k;
ll a[510][2], t[510][2], w[maxn];
ll dis[maxn][maxn];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	cin >> k;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			dis[i][j] = 1e18;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a[i][j];
			cin >> t[i][j];
		}
		dis[a[i][1]][a[i][2]] = t[i][1] + t[i][2];
		dis[a[i][2]][a[i][1]] = t[i][1] + t[i][2];
	}
	for (int k = 1; k <= m; ++k)
		for (int i = 1; i <= m; ++i) {
			if (dis[i][k] == 1e18)
				continue;
			for (int j = 1; j <= m; ++j)
				if (dis[k][j] != 1e18)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

		}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << '\n';
	}
}
