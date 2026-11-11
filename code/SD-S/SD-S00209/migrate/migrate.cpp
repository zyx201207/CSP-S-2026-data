#include <bits/stdc++.h>
#define endl '\n'
#define int long long

const int N = 2e6 + 10;
int x[N];
int min = 0x7fffffffffffffff, cnt = 0; 

void dfs1(int u, int n, int l, int end, int steps) {
//	std::cerr << u << ' ' << end << ' ' << steps << endl;
	if (u == end) {
		min = steps;
		return;
	}
	for (int i = u + 1; i <= n; i++) {
		if (x[i] - x[u] <= l && i <= end) {
			dfs1(i, n, l, end, steps + 1);
		}
	}
}

void dfs2(int u, int n, int l, int end, int steps) {
//	std::cerr << u << ' ' << end << ' ' << steps << endl;
	if (steps > min) return;
	if (cnt >= 3) return;
	if (u == end) {
		if (steps == min) cnt++;
	}
	for (int i = u + 1; i <= n; i++) {
		if (x[i] - x[u] <= l && i <= end) {
			dfs2(i, n, l, end, steps + 1);
		}
	}
}

signed main() {
	std::cin.tie(0) -> sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	std::cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			int n, l;
			std::cin >> n >> l;
			for (int i = 1; i <= n; i++) {
				std::cin >> x[i];
			}
			
			int d = x[2] - x[1];
			int ans = 0;
			if (d > (l / 2) || d <= (l / 3)) {
				std::cout << 0 << endl;
				continue;
			}
			for (int i = std::min((l / d + 2), n); i <= std::min((2 * (l / d)), n); i++) {
				ans += (n - i + 1);
			}
			std::cout << ans << endl;
		}
	} else if (c == 13 || c == 14) {
		while (t--) {
			int n, l;
			std::cin >> n >> l;
			for (int i = 1; i <= n; i++) {
				std::cin >> x[i];
			}
			
			std::vector<int> vec;
			for (int i = 1; i <= n; i++) {
				if (x[i] - x[1] <= l && x[n] - x[i] <= l) {
					vec.push_back(i);
				}
			}
			
			if (vec.size() >= 3) {
				std::cout << 0 << endl;
				continue;
			}
			
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int j = std::upper_bound(x + 1, x + n + 1, i + l) - x;
				ans += (n - j + 1);
			}
			std::cout << ans << endl;
		}
	} else {
		while (t--) {
			int n, l;
			std::cin >> n >> l;
			for (int i = 1; i <= n; i++) {
				std::cin >> x[i];
			}
			
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					min = 0x7fffffffffffffff, cnt = 0;
					dfs1(i, n, l, j, 0);
//					std::cerr << "--------DFS2--------" << endl;
					dfs2(i, n, l, j, 0);
					if (cnt == 2) ans++;
//					std::cerr << "ENDENDENDENDEND" << endl;
				}
			}
			std::cout << ans << endl;
//			std::cerr << "------------------------" << endl;
		}
	}
	return 0;
}
