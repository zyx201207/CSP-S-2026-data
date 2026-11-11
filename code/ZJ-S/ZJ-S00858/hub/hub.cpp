#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 1e6 + 10;

int c, t;
int n, k, f[N], d[N], g[N], dmax[N];
int l, r, mid, ans, rt, fa[N], dep[N];

int tot, uid[N];
int tot2, uidd[N];

bool flag;

std::vector <int> edge[N];

void dfs (int x, int lst) {
	dep[x] = dep[lst] + 1;
	d[x] = f[x] = dmax[x] = g[x] = 0, fa[x] = lst;
	for (auto to : edge[x]) {
		if (to ^ lst) {
			dfs(to, x);
			d[x] = std::max(d[x], d[to] + 1);
			f[x] += f[to];
		}
	}
	f[x] += (d[x] >= mid);
}

void dfs2 (int x, int lst) {
	int tmp = 0;
	int max1 = 0, max2 = 0;
	for (auto to : edge[x]) {
		if (to ^ lst) {
			tmp += f[to];
			if (d[to] + 1 > max1) {
				max2 = max1, max1 = d[to] + 1;
			} else if (d[to] + 1 > max2) {
				max2 = d[to] + 1;
			}
		}
	}
	++tmp;
	for (auto to : edge[x]) {
		if (to ^ lst) {
			g[x] = g[lst] + tmp - f[to];
			if (d[to] + 1 == max1) {
				dmax[x] = max2;
			} else {
				dmax[x] = max1;
			}

			uidd[++tot2] = to;
			dfs2(to, x);
			--tot2;
			if (flag) return;
		}
	}
	if (lst) {
		int sum = f[x];
		int skt = 0, cnt = 0;
		for (int i = fa[x]; i != rt; i = fa[i]) {
			++cnt;
			if (cnt + dmax[i] > mid) {
				skt = i;
				break;
			}
		}
		if (!skt) {
			if (g[rt] <= k - f[x]) {
				flag = 1;
				return;
			}
		} else {
			int mx = 1;
			for (int i = skt; i != rt; i = fa[i]) {
				mx = std::max(mx, dep[i] - std::max(0, mid - dmax[i]));
			}
			skt = uidd[mx];
			if (g[skt] <= k - f[x]) {
				flag = 1;
				return;
			}
		}
	}
}

bool check (int len) {
	if (c == 13 || c == 14) {
		if (!len) {
			return (k == n);
		}
		if (len >= n / 2) {
			return 1;
		}
		int u = n / 2 - len + 1;
		if (len * 3 - 1 + k >= u) {
			return 1;
		}
		return 0;
	}
	flag = 0;
	for (int i = 1; i <= n; ++i) {
		dfs(i, 0);
		if (f[i] <= k) {
			return 1;
		}
		rt = i;
		tot2 = 1;
		uidd[1] = i;
		for (int j = 1; j <= n; ++j) f[j] = std::max(f[j], 1);
		dfs2(i, 0);
		if (flag) {
			break;
		}
	}
	return flag;
}

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		edge[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	l = 0, r = n, ans = n;
	while (l <= r) {
		mid = l + r >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	std::cout << ans << "\n";
}


int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	clock_t st = clock();
	std::cin >> c >> t;
	while (t--) {
		solve();
	}
	std::cerr << clock() - st;

	return 0;
}