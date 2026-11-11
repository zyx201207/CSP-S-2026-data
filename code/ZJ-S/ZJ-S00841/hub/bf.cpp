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

int c, T, n, m, k, u[N], v[N];

vector<int> E[N];

int fa[N], dep[N], dfn[N], idfn[N], dcnt;
pair<int, int> pf[N][B];

inline void dfs0(int u) {
	dep[u] = dep[fa[u]] + 1;
	dfn[u] = ++dcnt;
	idfn[dcnt] = u;
	for (int v : E[u]) {
		if (v == fa[u]) {
			continue;
		}
		fa[v] = u;
		dfs0(v);
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

bool vis[N];

inline int lca(int u, int v) {
	if (u == v) {
		return u;
	}
	for (int i = 1; i <= n; ++i) {
		vis[i] = 0;
	}
	while (u) {
		vis[u] = 1;
		u = fa[u];
	}
	while (!vis[v]) {
		v = fa[v];
	}
	return v;
}

inline int dis(int u, int v) {
	return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		E[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		cin >> u[i] >> v[i];
		E[u[i]].emplace_back(v[i]);
		E[v[i]].emplace_back(u[i]);
	}
	init();
	int ans = n;
	for (int i = 0; i < 1 << n; ++i) {
		if (__builtin_popcount(i) != m) {
			continue;
		}
		int cnt = 0;
		for (int j = 1; j < n; ++j) {
			cnt += (i >> (u[j] - 1) & 1) && (i >> (v[j] - 1) & 1);
		}
		if (cnt < m - 2) {
			continue;
		}
		int d = 0;
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1) {
				continue;
			}
			int s = n;
			for (int k = 0; k < n; ++k) {
				if (i >> k & 1) {
					chkmin(s, dis(j + 1, k + 1));
				}
			}
			chkmax(d, s);
		}
		chkmin(ans, d);
	}
	cout << ans << "\n";
}

int main() {
	assert(freopen("hub.in", "r", stdin));
	assert(freopen("hub.ans", "w", stdout));
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}
