#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 5;
const int B = 20;

template <typename _Tp1, typename _Tp2>
inline void chkmin(_Tp1 &x, const _Tp2 &y) {
	x = min(x, static_cast<_Tp1>(y));
}

template <typename _Tp1, typename _Tp2>
inline void chkmax(_Tp1 &x, const _Tp2 &y) {
	x = max(x, static_cast<_Tp1>(y));
}

int c, T, n, m, k;

vector<int> E[N];

int fa[N], dep[N], maxd[N], smaxd[N], dfn[N], idfn[N], dcnt;
pair<int, int> pf[N][B];

inline void dfs0(int u) {
	dep[u] = dep[fa[u]] + 1;
	maxd[u] = dep[u];
	smaxd[u] = 0;
	dfn[u] = ++dcnt;
	idfn[dcnt] = u;
	for (int v : E[u]) {
		if (v == fa[u]) {
			continue;
		}
		fa[v] = u;
		dfs0(v);
		if (maxd[v] > smaxd[u]) {
			smaxd[u] = maxd[v];
			if (smaxd[u] > maxd[u]) {
				swap(maxd[u], smaxd[u]);
			}
		}
	}
}

inline void init() {
	dcnt = 0;
	dfs0(1);
	for (int i = 1; i <= n; ++i) {
		pf[i][0] = make_pair(dep[idfn[i]], idfn[i]);
	}
	for (int j = 1; j < B; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			pf[i][j] = min(pf[i][j - 1], pf[i + (1 << (j - 1))][j - 1]);
		}
	}
}

inline int lca(int u, int v) {
	if (u == v) {
		return u;
	}
	u = dfn[u], v = dfn[v];
	if (u > v) {
		swap(u, v);
	}
	int d = __builtin_clz(v - u) ^ 31;
	return fa[min(pf[u + 1][d], pf[v - (1 << d) + 1][d]).second];
}

inline int dis(int u, int v) {
	return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

int f0[N], f[N];
int s[N], g0[N], g[N];

inline bool check1(int fa, int u, int t) {
	if (dis(u, t) > k && lca(u, t) != t) {
		return 0;
	}
	for (int v : E[u]) {
		if (v != fa) {
			if (!check1(u, v, t)) {
				return 0;
			}
		}
	}
	return 1;
}

inline bool check2(int fa, int u, int t, int d) {
	if (u == t) {
		return 1;
	}
	if (d > k) {
		return 0;
	}
	for (int v : E[u]) {
		if (v != fa) {
			if (!check2(u, v, t, d + 1)) {
				return 0;
			}
		}
	}
	return 1;
}

inline bool check() {
	for (int i = n; i; --i) {
		int u = idfn[i];
		f0[u] = maxd[u] - dep[u] >= k;
		for (int v : E[u]) {
			if (v != fa[u]) {
				f0[u] += f0[v];
			}
		}
	}
	g0[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int u = idfn[i], sum = 0;
		for (int v : E[u]) {
			if (v != fa[u]) {
				sum += f0[v];
			}
		}
		for (int v : E[u]) {
			if (v != fa[u]) {
				g0[v] = g0[u] + sum - f0[v];
				int d = 0;
				if (maxd[u] == maxd[v]) {
					d = smaxd[u] - dep[u];
				} else {
					d = maxd[u] - dep[u];
				}
				d = max(d, s[u]);
				if (d >= k) {
					++g0[v];
				}
				s[v] = d + 1;
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		if (f0[u] == 0) {
			f0[u] = 1;
		}
		if (g0[u] == 0) {
			g0[u] = 1;
		}
		f[u] = f0[u];
		g[u] = g0[u];
	}
	for (int u = 1; u <= n; ++u) {
		int v = u;
		while (fa[v]) {
			int p = fa[v], d = 0;
			if (maxd[v] == maxd[p]) {
				d = smaxd[p];
			} else {
				d = maxd[p];
			}
			if (dep[u] + d - 2 * dep[p] > k) {
				break;
			}
			v = fa[v];
		}
		chkmin(f[v], f0[u]);
	}
	for (int u = 2; u <= n; ++u) {
		if (f0[u] >= m) {
			continue;
		}
		for (int v = 2; v <= n; ++v) {
			if (lca(u, v) == v) {
				continue;
			}
			if (check1(v, fa[v], u)) {
				chkmin(g[v], f0[u]);
			}
		}
	}
	for (int u = 2; u <= n; ++u) {
		if (g0[u] >= m) {
			continue;
		}
		for (int v = 2; v <= n; ++v) {
			if (lca(u, v) == u && check2(fa[u], u, v, 1)) {
				chkmin(g[v], g0[u]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int u = idfn[i];
		for (int v : E[u]) {
			if (v != fa[u]) {
				chkmin(f[v], f[u]);
			}
		}
	}
	if (f[1] <= m) {
		return 1;
	}
	for (int u = 2; u <= n; ++u) {
		if (f[u] + g[u] <= m) {
			return 1;
		}
	}
	return 0;
}

inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		E[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	init();
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		k = mid;
		if (check()) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << l << "\n";
}

int main() {
	assert(freopen("hub.in", "r", stdin));
	assert(freopen("hub.out", "w", stdout));
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}
