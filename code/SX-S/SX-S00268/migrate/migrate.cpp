#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, d, a[2000005], nxt[2000005], pre[2000005], sonl[2000005], sonr[2000005], f[2000005][3];

inline bool chk(int x, int y) {
	if (sonl[x] <= y && sonr[x] >= y)
		return true;
	return false;
}

inline int calc(int l, int r, int x) {
	if (r <= x)
		return 0;
	if (x < l)
		return r - l + 1;
	return r - x;
}

void work() {
	n = read();
	d = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	for (int i = 1, j = 1; i <= n; ++i) {
		while (j < n && a[j + 1] - a[i] <= d)
			++j;
		if (j == i)
			nxt[i] = -1;
		else
			nxt[i] = j;
	}
	for (int i = n, j = n; i >= 1; --i) {
		while (j > 1 && a[i] - a[j - 1] <= d) {
			--j;
		}
		if (j == i)
			pre[i] = -1;
		else
			pre[i] = j;
	}
	for (int i = 1; i <= n; ++i) {
		sonl[i] = n + 1;
		sonr[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		if (pre[i] == -1)
			continue;
		sonl[pre[i]] = min(sonl[pre[i]], i);
		sonr[pre[i]] = max(sonr[pre[i]], i);
	}
	for (int i = n; i >= 2; --i) {
		f[i][0] = calc(sonl[i], sonr[i], i);
		f[i][1] = calc(sonl[i - 1], sonr[i - 1], i);
		f[i][2] = 0;
		if (nxt[i] != -1) {
			if (chk(i, nxt[i] - 1)) {
				f[i][2] += f[nxt[i]][1];
			}
			if (chk(i, nxt[i])) {
				f[i][2] += f[nxt[i]][2];
				f[i][0] += f[nxt[i]][0];
			}
			if (chk(i - 1, nxt[i])) {
				f[i][1] += f[nxt[i]][0];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (nxt[i] != -1) {
			ans += f[nxt[i]][1] + f[nxt[i]][2];
		}
	}
	printf("%lld\n", ans);
	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int Tec = read(), T = read();
	while (T--) {
		work();
	}
	return 0;
}