#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 2e6 + 10;

int c, t;
int n;
int pre[N], suf[N];

int tot, l[N], r[N], ll[N], rr[N];

i64 ans;
i64 dd[N];
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
	for (int i = 1; i <= n; ++i) {
		int l = i + 1, r = n, mid = 0, pos = i;
		while (l <= r) {
			mid = l + r >> 1;
			if (a[mid] - a[i] <= d) {
				pos = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		suf[i] = pos;
	}

	if (c <= 10) {
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
			dd[i] = 0;
		}

		ans = 0;
		//pos - 1
		if (pos >= 2) {
			for (int i = 1; i < pos - 1; ++i) {
				int r = suf[pos - 1], l = pos + 1;
				int r2 = suf[pos - 2];
				int g = i + 1;
				if (pos + 1 <= n) {
					g = pre[pos + 1];
				}
				if (g <= i) {
					continue;
				}
				ans += r - r2;
			}
		}

		//pos + 1
		if (pos + 1 <= n) {
			for (int i = n; i > pos + 1; --i) {
				int r = pre[pos + 1];
				int r2 = pre[pos + 2];
				int g = i - 1;
				if (pos - 1 >= 1) {
					g = suf[pos - 1];
				}
				if (g >= i) {
					continue;
				}
				ans += r2 - r;
			}
		}

		std::cout << ans << "\n";
		return;
	}

	ans = 0;
	for (int i = 1; i <= n; ++i) {
		int o = i;
		tot = 0;
		r[0] = i;
		for (int j = 1; ; ++j) {
			int lo = o;
			o = suf[o];
			if (lo == o || !o) {
				break;
			}
			++tot;
			l[tot] = r[tot - 1] + 1, r[tot] = o;
		}
		rr[1] = l[1] - 1, ll[1] = l[1];
		for (int j = 2; j <= tot; ++j) {
			if (l[j - 1] == r[j - 1]) {
				ll[j] = l[j], rr[j] = l[j] - 1;
				continue;
			}

			int fl = l[j], fr = r[j], mid = 0, poss = l[j];
			while (fl <= fr) {
				mid = fl + fr >> 1;
				if (pre[mid] != r[j - 1] - 1) {
					poss = mid;
					fl = mid + 1;
				} else {
					fr = mid - 1;
				}
			}
			rr[j] = poss;
			fl = l[j], fr = rr[j], mid = 0, poss = 0;
			while (fl <= fr) {
				mid = fl + fr >> 1;
				if (pre[mid] <= r[j - 1] - 2) {
					poss = mid;
					fl = mid + 1;
				} else {
					if (rr[j - 1] >= r[j] - 1) {
						poss = mid;
						fl = mid + 1;
					} else {
						fr = mid - 1;
					}
				}
			}
			ll[j] = poss + 1;
			ans += rr[j] - ll[j] + 1;
		}
	}
	std::cout << ans << "\n";
}


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> c >> t;
	clock_t st = clock();
	while (t--) {
		solve();
	}
	std::cerr << clock() - st;

	return 0;
}