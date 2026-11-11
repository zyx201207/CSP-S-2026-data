#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
int cid, T, n, k, dep[N], best, cent, judge, sum = 0;
basic_string<int> vec[N];
const int inf = 0x3f3f3f3f;
void dfs(int u, int fa) {
	dep[u] = 1;
	for (int v : vec[u]) 
		if (v != fa) dfs(v, u), dep[u] = max(dep[u], dep[v] + 1);
	if (dep[u] == judge) cent = u;
	if (dep[u] >= judge) ++sum;
}
int eu[N], ev[N], tmpcent;
inline int solve(int u) {
	cent = sum = 0, dfs(u, 0), tmpcent = cent;
	if (!cent) return 1;
	sum = 0, dfs(cent, 0);
	return sum;
}

int f[N], g[N], dfa[N], h[N], sec[N], sov[N], all[N], ier[N];
inline void build(int u) {
	dep[u] = 1, f[u] = 0, h[u] = 0, sec[u] = 1;
	for (int v : vec[u])
		if (v != dfa[u]) {
			dfa[v] = u, build(v);
			// dep[u] = max(dep[u], dep[v] + 1);
			if (dep[v] + 1 > dep[u]) sec[u] = dep[u], dep[u] = dep[v] + 1;
			else if (dep[v] + 1 > sec[u]) sec[u] = dep[v] + 1;
			f[u] += f[v];
		}
	f[u] += dep[u] >= judge;
}
inline void calch(int u, int ims) {
	++ims;
	for (int v : vec[u])
		if (v != dfa[u]) {
			h[v] = h[u] + f[u] - f[v] - (dep[u] >= judge);
			int rdep = (dep[v] + 1 == dep[u] ? sec[u] : dep[u]);
			int qwq = max(0, judge - rdep);
			h[v] += ims - min(ims, qwq), calch(v, min(ims, qwq));
			// if (rdep == )
		}
}
inline void calcsum(int u) {
	for (int v : vec[u])
		if (v != dfa[u]) calcsum(v);
	if (dep[u] == judge) all[u] = sov[u] = 1;
	else if (dep[u] > judge) {
		int fl = 0;
		all[u] = 1;
		for (int v : vec[u])
			if (v != dfa[u]) all[u] += all[v];
		int edep = 1;
		for (int v : vec[u]) if (v != dfa[u]) {
			if (!fl && dep[v] >= judge) fl = v;
			if (v != fl) sov[u] += all[v], edep = max(edep, dep[v] + 1);
			else sov[u] += sov[v];
		}
		ier[u] = ier[fl] + 1;
		int mxer = max(0, judge - edep);
		if (mxer < ier[u]) sov[u] += ier[u] - mxer, ier[u] = mxer;
	}
}

inline bool check(int judgek) {
	judge = judgek + 1;
	best = solve(1);
	if (best <= k) return 1;
	if (best > 2) {
		int ec = tmpcent;
		for (int i = 1; i <= n; i++) dfa[i] = 0, h[i] = 0, all[i] = sov[i] = ier[i] = 0;
		build(ec);
		calch(ec, 0);
		calcsum(ec);
		for (int i = 1; i < n; i++) {
			int u = eu[i], v = ev[i];
			if (dfa[u] == v) swap(u, v);
			int lol = h[v] + max(1, sov[v]);
			if (lol <= k) return 1;
		}
	}
	return 0;
}
inline void work() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) vec[i].clear();
	for (int i = 1, u, v; i < n; i++) cin >> u >> v, eu[i] = u, ev[i] = v, vec[u] += v, vec[v] += u;
	int l = 0, r = n - 1, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
}
int main() {
	// freopen("hub.in", "r", stdin);
	// freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> cid >> T;
	while (T--) work();
	cerr << double(clock()) / CLOCKS_PER_SEC << endl;
	return 0;
}
