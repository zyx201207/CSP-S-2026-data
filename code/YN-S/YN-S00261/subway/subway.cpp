#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
const int M = 20010, N = 510, inf = 1e18;
int a[N][M], t[N][M];
int w[M], ans = inf, k[N];
int c, n, m, d, q;

void dfs(int u, int ed, int w, int now, int nowpos) {
	if (u == ed) {
		ans = std::min(ans, w);
		return;
	}
	if (w > ans)
		return;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (a[i][j] == u && i != now) {
				dfs(u, ed, w + t[now][nowpos] + t[i][j], i, j);
			}
		}
	}
	if (now != 0) {
		int l = nowpos - 1, r = nowpos + 1;
		while (l > 0 || r <= k[now]) {
			if (l > 0) {
				l--;
				dfs(a[now][l], ed, w + t[now][l], now, l);
			}
			if (r <= k[now]) {
				dfs(a[now][r], ed, w + t[now][r], now, r);
				r++;
			}
			if (l <= 0 && r > k[now])
				break;
			std::cout << "afqaf\n";
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		std::cin >> w[i];
	for (int i = 1; i <= n; i++) {
		std::cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			std::cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		dfs(x, y, 0, 0, 0);
		std::cout << ans << "\n";
	}
	return 0;
}
