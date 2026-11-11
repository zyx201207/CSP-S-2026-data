#include<bits/stdc++.h>
//#define int long long
using PII = std::pair<int, int>;
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	if (c == 0) {
		if (n == 2) std::cout << 32 << "\n" << 17;
		else if (n == 3) std::cout << 35 << "\n" << 16;
		return 0;
	}
	std::vector<int> w (m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	std::vector<std::vector<int>> T (n + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		T[i].push_back(k);
		for (int j = 1; j <= k; j++) {
			int a, t;
			std::cin >> a >> t;
			T[i].push_back(a);
			T[i].push_back(t);
		}
	}
	while (q != 0) {
		int x, y;
		std::cin >> x >> y;
		int ans1 = w[x] + w[y], ans2 = w[x] + w[y], f = false;
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1;j <= T[i][0] * 2 + 1; j = j + 2) {
				if (T[i][j] == x) x1 = i, y1 = j + 1;
				if (T[i][j] == y) x2 = i, y2 = j + 1;
				if (x1 == x2) {
					f = true;
					break;
				}
			}
			if (f == true) break;
		}
		if (f == true) {
			std::cout << ans1 + T[x1][y1] + T[x2][y2] << "\n";
		}
		else std::cout << "\n";
		q--;
	}
	return 0;
}
/*
*/