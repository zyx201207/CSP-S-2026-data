#include <bits/stdc++.h>

int n, r[2000005], l[2000005];
long long a[2000005], ans = 0, d, f[2000005], g[2000005];

void read(long long &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}

void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	ans = 0;
	int le = 1;
	for (int i = 1; i <= n; ++i) {
		while (a[i] - a[le] > d) {
			++le;
		}
		l[i] = le;
	}
	int ri = n;
	for (int i = n; i >= 1; --i) {
		while (a[ri] - a[i] > d) {
			--ri;
		}
		r[i] = ri;
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (l[i] == l[i + 1]) {
			g[i] = 0;
		} else {
			g[i] = l[i + 1] - l[i];
//			if (l[i] < i && (i == 1 || l[i - 1] == l[i])) {
//				g[i] += g[l[i]];
//			}
			if (l[i] < i) {
				g[i] += g[l[i]];
			}
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		if (r[i] == r[i + 1]) {
			f[i] = 0;
		} else {
			f[i] = r[i + 1] - r[i];
//			if (r[i + 1] > i + 1 && (r[i + 1] == r[i + 2] || i + 2 > n)) {
//				f[i] += f[r[i + 1] - 1];
//			}
			if (r[i + 1] > i + 1) {
				f[i] += f[r[i + 1] - 1];
			}
		}
	}
	for (int i = 2; i <= n - 2; ++i) {
//		if (r[i] > std::max(r[i - 1], i + 1) && l[i + 1] < std::min(l[i + 2], i)) {
//			int d1 = std::max(0, i + 1 - r[i - 1]), d2 = std::max(0, l[i + 2] - i);
//			// ans += 1ll * (g[i + 1] - d2) * (f[i - 1] - d1);
//			ans += 1ll * g[i + 1] * f[i - 1];
////			if (g[i + 1] > 0 && f[i - 1] > 0) {
////				printf("b = %d, c = %d, le = %d, ri = %d\n", i, i + 1, g[i + 1] - d2, f[i - 1] - d1);
////			}
//		}
//		if (g[i + 1] > 0 && f[i - 1] > 0) {
//			printf("b = %d, c = %d, le = %d, ri = %d\n", i, i + 1, g[i + 1], f[i - 1]);
//		}
		if (r[i] <= i + 1 || l[i + 1] >= i) {
			continue;
		}
		int d1 = std::max(0, i + 1 - r[i - 1]), d2 = std::max(0, l[i + 2] - i);
		int L = 0, R = 0;
		if (r[i] < r[i + 1]) {
			R = r[i] - r[i - 1];
		} else {
			R = f[i - 1];
		}
		if (l[i] < l[i + 1]) {
			L = l[i + 2] - l[i + 1];
		} else {
			L = g[i + 1];
		}
		ans += 1ll * (L - d2) * (R - d1);
	}
	printf("%lld\n", ans);
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		solve();
	}
	return 0;
}
