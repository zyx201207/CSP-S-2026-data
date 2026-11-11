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
} // namespace FindMid;

int ht[N];
void init(int u, int f) {
	ht[u] = 0;
	for (auto v : G[u]) {
		if (v != f) {
			init(v, u);
			ht[u] = max(ht[u], ht[v] + 1);
		}
	}
}

int nbr[N];
bool mark[N], vis[N];
int limit[N];
void search(int u, int f, vi &tar) {
	tar.pb(u);
	vis[u] = 1;
	for (auto v : G[u]) {
		if (v != f && mark[v] && nbr[v] <= 2) {
			search(v, u, tar);
		}
	}
}
int work(vi chain, int lim, int res = 0) {
	bool lsit = nbr[chain[0]] == 1;
	bool rsit = nbr[chain.back()] == 1;
	int l = 0, len = sz(chain);
	if (lsit) {
		int glim = -1e9;
		rep(i, 0, len - rsit) {
			int u = chain[i];
			glim = max(glim, limit[u] - i);
			if (glim + i + 1 > lim) {
				break;
			}
			res = max(res, i + 1);
		}
		l = 1;
	}
	if (rsit) {
		int glim = -1e9;
		per(i, len, lsit) {
			int u = chain[i];
			glim = max(glim, limit[u] + i);
			if (glim - i + 1 > lim) {
				break;
			}
			res = max(res, len - i);
		}
	}

	deque < pii > Q[2]; // 0: limit[u] + i
	int bound = lsit;
	auto addr = [&](deque < pii > &que, int op, int i) {
		int u = chain[i];
		pii ins = pii(op ? limit[u] - i : limit[u] + i, i);
		for (; sz(que) && que.back().fi < ins.fi; que.pop_back());
		que.pb(ins);
	};
	auto dell = [&](deque < pii > &que, int ddl) {
		for (; sz(que) && que[0].se < ddl; que.pop_front());
	};

	addr(Q[0], 0, bound);
	auto check = [&](int L, int R) {
		int mid = (L + R) >> 1;
		dell(Q[1], mid + 1);
		for (; bound < mid; addr(Q[0], 0, ++bound));
		dell(Q[0], L);
		int llim = sz(Q[0]) ? Q[0][0].fi : -inf;
		int rlim = sz(Q[1]) ? Q[1][0].fi : -inf;
//		cerr << llim << ' ' << rlim << '\n';
		return llim - L + 1 <= lim && rlim + R + 1 <= lim;
	};
//	for (auto x : chain) cerr << limit[x] << " ";
//	cerr << '\n';
	rep(r, lsit, len - rsit) {
		addr(Q[1], 1, r);
		for (; l <= r && !check(l, r); l++);
		res = max(res, r - l + 1);
//		cerr << l << ' ' << r << " qwq\n";
	}
	/*
	rep(l, 0, sz(chain)) {
		rep(r, l, sz(chain)) {
			int glim = 0;
			L(i, l, r) {
				int tlim = 1e9, u = chain[i];
				if (!lsit || l) {
					tlim = min(tlim, limit[u] + i - l + 1);
				}
				if (!rsit || r < sz(chain) - 1) {
					tlim = min(tlim, limit[u] + r - i + 1);
				}
				glim = max(glim, tlim);
			}
			if (glim <= lim) {
				res = max(res, r - l + 1);
			}
		}
	}
	*/
	return res;
}
bool check(int lim) {
	int bas = 0, res = 0;
	L(i, 1, n) {
		bas += mark[i] = ht[i] >= lim;
		vis[i] = 0;
	}
	if (bas <= k) {
		return 1;
	}
	L(i, 1, n) {
		nbr[i] = 0;
		for (int j : G[i]) {
			nbr[i] += mark[j];
		}
	}
	L(i, 1, n) {
		limit[i] = 0;
		if (mark[i]) {
			for (auto j : G[i]) {
				if (!mark[j]) {
					limit[i] = max(limit[i], ht[j] + 1);
				}
			}
		}
	}
	L(i, 1, n) {
		if (!vis[i] && mark[i] && nbr[i] <= 2) {
			vi vec;
			vis[i] = 1;
			for (auto j : G[i]) {
				if (mark[j] && nbr[j] <= 2) {
					vi rec;
					search(j, i, rec);
					if (!sz(vec)) {
						reverse(all(rec));
						vec = rec;
						vec.pb(i);
					} else {
						vec.insert(vec.end(), all(rec));
					}
				}
			}
			if (!sz(vec)) {
				vec = {i};
			}
			res = max(res, work(vec, lim));
		}
	}
	return bas - res <= k;
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

	tie(rt, D) = FindMid::get();
	init(rt, 0);

	int l = 0, r = (D + 1) / 2, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	} 

	cout << l << '\n';
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
	double tbe = clock();
	FileIO("hub");
    Decimal10::main();
    cerr << "time: " << (clock() - tbe) / CLOCKS_PER_SEC << "ms\n";
    cerr << "memory: " << (&med - &mbe) / 1048576.0 << "MiB\n";
    return 0;
}

// 17:12 passed all samples