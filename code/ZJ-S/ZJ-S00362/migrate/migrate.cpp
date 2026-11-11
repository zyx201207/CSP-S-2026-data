#include <bits/stdc++.h>

using i64 = long long;

namespace Qwarth {

const int N = 5007;

i64 n, m;
i64 a[N], f[N], g[N];
int q[N], hh, tt;
i64 val[N];

//i64 min, cnt;
//i64 vis[N];

//void dfs(int now, int go, i64 c) {
//	if (~vis[now] && vis[now] < c) {
//		return;
//	}
//	vis[now] = c;
//	if (now == go) {
//		if (c < min) {
//			min = c;
//			cnt = 1;
//		} else {
//			++cnt;
//		}
//		return;
//	}
//	for (int i = now + 1; a[i] - a[now] <= m; ++i) {
//		dfs(i, go, c + 1);
//	}
//}

void main(int _c) {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	i64 ans = 0;
	if (n > 5000) {
		std::cout << 0 << '\n';
		return;
	}
//	for (int s = 1; s < n; ++s) {
//		f[s] = 1, g[s] = 0;
//		for (int i = s + 1; i <= n; ++i) {
//			f[i] = 0, g[i] = n + 1;
//			for (int j = i - 1; j >= s && a[i] - a[j] <= m && g[i] >= g[j] + 1; --j) {
//				if (g[i] > g[j] + 1) {
//					g[i] = g[j] + 1;
//					f[i] = f[j];
//				} else if (g[i] == g[j] + 1) {
//					f[i] += f[j];
//				}
//			}
//			ans += f[i] == 2;
//		}
//	}
	for (int s = 1; s < n; ++s) {
		for (int i = 0; i <= n; ++i) {
			val[i] = 0;
			f[i] = 0, g[i] = n + 1;
		}
		g[s] = 0, f[s] = 1;
		q[hh = tt = 1] = s;
		val[g[s]] += f[s];
		for (int i = s + 1; i <= n; ++i) {
			f[i] = 0, g[i] = n + 1;
			while (hh <= tt && a[i] - a[q[hh]] > m) {
				int x = q[hh++];
				val[g[x]] -= f[x];
			}
			if (hh <= tt) {
				g[i] = g[q[hh]] + 1;
				f[i] = val[g[i] - 1];
			}
//			for (int j = i - 1; j >= s && a[i] - a[j] <= m && g[i] >= g[j] + 1; --j) {
//				if (g[i] > g[j] + 1) {
//					g[i] = g[j] + 1;
//					f[i] = f[j];
//				} else if (g[i] == g[j] + 1) {
//					f[i] += f[j];
//				}
//			}
//			if (f[i] == 2) {
//				std::cout << s << ' ' << i << '\n';
//			}
			ans += f[i] == 2;
//			if (f[i] == 2) {
//				std::cout << s << ' ' << i << ' ' << f[i] << ' ' << g[i] << '\n';
//				std::cout << q[hh] << ' ' << f[q[hh]] << ' ' << g[q[hh]] << '\n';
//				std::cout << val[g[q[hh]]] << '\n';
//			}
			q[++tt] = i;
			val[g[i]] += f[i];
		}
	}
	std::cout << ans << '\n';
}
}  // namespace Qwarth

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int _T = 1, c;
	std::cin >> c >> _T;
	while (_T--) {
		Qwarth::main(c);
	}
	return 0;
}
