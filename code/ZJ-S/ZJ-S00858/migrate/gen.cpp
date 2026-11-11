#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

std::mt19937_64 rnd(time(0));

i64 myrand (i64 l, i64 r) {
	return rnd() % (r - l + 1) + l;
}

const int N = 2e6 + 10;

int c, t;
int n;
int pre[N];

i64 ans;
i64 d, a[N], f[N], g[N], s[N];

void solve() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	
		int l = 1, r = i - 1, mid = 0, pos = i;
		while (l <= r) {
			mid = l + r >> 1;
			if (a[i] - a[mid] <= d) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		pre[i] = pos;
	}

	if (n <= 5000) {
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			f[i] = 0, g[i] = 1, s[i] = 1;
			int lst = 0;
			for (int j = i + 1; j <= n; ++j) {
				if (a[j] - a[i] <= d) {
					f[j] = 1;
					g[j] = 1;
				} else {
					f[j] = f[pre[j]] + 1;
					if (f[j] != f[j - 1]) {
						lst = j - 1;
					}
					g[j] = s[lst] - s[pre[j] - 1];
					if (g[j] >= 3) g[j] = 3;
				}

				s[j] = s[j - 1] + g[j];
				ans += (g[j] == 2);
			}
		}
		std::cout << ans << "\n";
		return;
	}
	if (c == 11 || c == 12) {
		if (n == 1) {
			std::cout << "0\n";
			return;
		}
		i64 u = a[2] - a[1];
		i64 v = d / u;
		if (v >= n || v <= 1) {
			std::cout << "0\n";
			return;
		}
		std::cout << std::max(0LL, n - (v * 2 - 1)) << "\n";
		return;
	}
	if (c == 13 || c == 14) {
		int pos = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] - a[1] <= d && a[n] - a[i] <= d) {
				pos = i;
			}
		}
		std::cout << pos << "\n";
		return;
	}
}

i64 gg[100010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.in", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cout << "13 10\n";
	for (int i = 1; i <= 10; ++i) {
		int n = 5e3;
		i64 d = myrand(1e17, 1e18), ff = std::min(d * 2, (i64)1e18), lst = 0;
		for (int j = 1; j <= n; ++j) {
			gg[j] = myrand(0, ff);
		}
		gg[1] = d;
		std::sort(gg + 1, gg + n + 1);
		std::cout << n << ' ' << d << std::endl;
		for (int j = 1; j <= n; ++j) std::cout << gg[j] << ' ';
		std::cout << std::endl;
	}

	return 0;
}