#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e6 + 5;

int c, T, n, pre[N], nxt[N], c1[N], c2[N], f[N], g[N];
ll d, a[N];

inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1, j = 1; i <= n; ++i) {
		while (a[i] - a[j] > d) {
			++j;
		}
		pre[i] = j;
	}
	for (int i = n, j = n; i; --i) {
		while (a[j] - a[i] > d) {
			--j;
		}
		nxt[i] = j;
	}
	for (int i = 1; i <= n; ++i) {
		c1[i] = c2[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (nxt[i] != i) {
			++c1[nxt[i]];
		}
		if (pre[i] != i) {
			++c2[pre[i]];
		}
	}
	for (int i = 1; i <= n; ++i) {
		f[i] = c1[i];
		if (pre[i] < i && nxt[pre[i]] == i) {
			f[i] += f[pre[i]];
		}
	}
	for (int i = n; i; --i) {
		g[i] = c2[i];
		if (nxt[i] > i && pre[nxt[i]] == i) {
			g[i] += g[nxt[i]];
		}
	}
	ull ans = 0;
	for (int i = 1; i < n; ++i) {
		if (pre[i + 1] >= i || nxt[i] <= i + 1) {
			continue;
		}
		int p = min(pre[i + 2] - 1, i - 1) - pre[i] + 1;
		if (pre[i] == pre[i + 1]) {
			if (pre[i + 2] > pre[i]) {
				p += f[pre[i]];
			}
		} else {
			p = min(pre[i + 2] - 1, i - 1) - pre[i + 1] + 1;
		}
		int q = nxt[i] - max(nxt[i - 1] + 1, i + 2) + 1;
		if (nxt[i] == nxt[i + 1]) {
			if (nxt[i - 1] < nxt[i]) {
				q += g[nxt[i]];
			}
		}
		ans += (ull)p * q;
	}
	cout << ans << "\n";
}

int main() {
	assert(freopen("migrate.in", "r", stdin));
	assert(freopen("migrate.out", "w", stdout));
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}
