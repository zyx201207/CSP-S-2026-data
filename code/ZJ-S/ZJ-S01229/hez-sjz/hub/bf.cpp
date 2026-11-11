#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie(0) -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= (int)(r); i++)
#define R(i, r, l) for (int i = r; i >= (int)(l); i--)
#define rep(i, l, r) for (int i = l; i < (int)(r); i++)
#define per(i, r, l) for (int i = r - 1; i >= (int)(l); i--)
#define FileIO(name) \
    freopen(name ".in", "r", stdin); \
    freopen(name ".out", "w", stdout)

bool mbe;
int tid;
namespace Decimal10 {
const int N = 1e6 + 6;
const int inf = 1e9;
int n, k, rt, D;
vi G[N];

namespace FindMid {
int dep[N], fa[N];
void dfs(int u, int f) {
	dep[u] = dep[f] + 1;
	fa[u] = f;
	for (auto v : G[u]) {
		if (v != f) {
			dfs(v, u);
		}
	}
}
pii get() {
	dfs(1, 0);
	int u = max_element(dep + 1, dep + n + 1) - dep;
	dfs(u, 0);
	u = max_element(dep + 1, dep + n + 1) - dep;
	int diam = dep[u] - 1;
	L(_, 1, diam / 2) {
		u = fa[u];
	}
	return {u, diam};
}
}

int par[N], dep[N];
void init(int u, int f) {
	par[u] = f;
	dep[u] = dep[f] + 1;
	for (auto v : G[u]) {
		if (v != f) {
			init(v, u);
		}
	}
}
int dist(int u, int v) {
	int res = 0;
	for (; u != v; u = par[u], res++) {
		if (dep[u] < dep[v]) swap(u, v);
	}
	return res;
}

int ans;
int fa[N];
bool mark[N];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void chkans() {
	iota(fa + 1, fa + n + 1, 1);
	L(i, 1, n) {
		if (mark[i]) {
			for (auto j : G[i]) {
				if (mark[j]) {
					fa[find(i)] = find(j);
				}
			}
		}
	}
	int ccs = 0;
	L(i, 1, n) {
		if (mark[i] && fa[i] == i) {
			ccs++;
		}
	}
	if (ccs > 2) {
		return;
	}
	int res = 0;
	L(i, 1, n) {
		int mind = inf;
		L(j, 1, n) {
			if (mark[j]) {
				mind = min(mind, dist(i, j));
			}
		}
		res = max(res, mind);
	}
	ans = min(ans, res);
}

void baosou(int p, int c) {
	if (p == n + 1) {
		if (c == 0) chkans();
		return;
	}
	if (c) {
		mark[p] = 1;
		baosou(p + 1, c - 1);
		mark[p] = 0;
	}
	baosou(p + 1, c);
}

void solve() {
	cin >> n >> k;
	L(i, 1, n) {
		vi().swap(G[i]);
	}

	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}

	ans = inf;
	init(1, 0);
	baosou(1, k);

	cout << ans << '\n';
}

int main() {
	int T;
	qio(), cin >> tid >> T;
	L(i, 1, T) {
		solve();
	}
    return 0;
}
} // namespace Decimal10
bool med;

int main() {
    Decimal10::main();
    return 0;
}