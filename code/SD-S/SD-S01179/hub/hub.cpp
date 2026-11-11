#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

constexpr int MaxN = 1e6 + 10;

int n, k;
vector<int> G[MaxN];

int D;
int len[MaxN], f[MaxN];
int dfn[MaxN], rdfn[MaxN], tim = 0;
void dfs1(int u, int par) {
	len[u] = 0;
	f[u] = 0;
	dfn[u] = ++tim;
	for (auto v : G[u]) if (v != par) {
		dfs1(v, u);
		f[u] += f[v];
		len[u] = max(len[u], len[v] + 1);
	}
	rdfn[u] = ++tim;
	if (len[u] >= D)
	   f[u]++;
}

int ban = 0;
int ff[MaxN], gg[MaxN];
int seq[MaxN], siz = 0;
void dfs2(int u, int par) {
	ff[u] = 0;
	if (dfn[u] < dfn[ban] && dfn[u] > rdfn[ban])
	   seq[++siz] = u;
	for (auto v : G[u]) if (v != par) {
		dfs2(v, u);
		ff[u] = max(ff[u], ff[v] + 1);
	}
}
void dfs3(int u, int par) {
	gg[u] = gg[par] + 1;
	ff[u] = min(ff[u], gg[u]);
	for (auto v : G[u]) if (v != par) {
		dfs3(v, u);
	}
}

bool check(int d) {
//	debug(" check %d\n", d);
	D = d;
	dfs1(1, 0);
	for (int u = 2; u <= n; u++) {
		ban = u;
//		debug(" ban %d, f = %d\n", u, f[u]);
		siz = 0;
		
		for (int i = 1; i <= n; i++)
			ff[i] = len[i];
		
		dfs2(u, 0);
		gg[u] = 0;
		for (auto v : G[u]) dfs3(v, u);
//		debug("ff[] = ");
//		for (int i = 1; i <= n; i++)
//			debug("%d ", ff[i]);
//		debug("\n");
		
		int cnt = max(f[u], 1);
		for (int t = 1; t <= siz; t++)
			cnt += ff[seq[t]] >= D;
//		debug(" cnt = %d\n", cnt);
		if (cnt <= k) return true; 
	}
	return false;
}

void solve() {
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		G[i].clear(); 
	
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	
	int l = 0, r = n, res = n;
	while (l <= r) {
		const int mid = (l + r) >> 1;
		if (check(mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	
	cout << res << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int cid, T;
	cin >> cid >> T;
	while (T--) solve();
}

/*
0 1
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
*/

/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

/*
坐落于大都市顶点空想构筑的理想乡
将这一切湮灭的将是谁的愿望
*/

