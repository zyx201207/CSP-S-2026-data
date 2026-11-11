#include <bits/stdc++.h>
#define nmf(i, s, e) for (int i = s; i <= e; i++)
#define ref(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int c;
struct DSU {
	int fa[15];
	int find(int x) {
		return (x == fa[x]) ? (x) : (fa[x] = find(fa[x]));
	}
	void init(int n) {
		nmf(i, 1, n)fa[i] = i;
	}
	void merge(int x, int y) {
		if (find(x) == find(y))return;
		fa[find(x)] = find(y);
	}
} U;
int n, k;
vector<int> grh[15];
int dis[15][15];
void dfs(int u, int fa, int rt) {
	for (auto v : grh[u]) {
		if (v == fa)continue;
		dis[rt][v] = dis[rt][u] + 1;
		dfs(v, u, rt);
	}
}
void solve() {
	cin >> n >> k;
	nmf(i, 1, n)grh[i].clear();
	nmf(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		grh[u].push_back(v);
		grh[v].push_back(u);
	}
	nmf(i, 1, n)dfs(i, 0, i);
	int ans = 0x3f3f3f3f;
	nmf(i, 0, (1 << n) - 1) {
		if (__builtin_popcount(i) != k)continue;
		U.init(n);
		nmf(u, 1, n) {
			if ((i & (1 << (u - 1)))) {
				for (auto v : grh[u]) {
					if ((i & (1 << (v - 1))))
						U.merge(u, v);
				}
			}
		}
		set<int> s;
		nmf(u, 1, n) {
			if ((i & (1 << (u - 1)))) {
				s.insert(U.find(u));
			}
		}
		if (s.size() > 2)continue;
		int mx = 0;
		nmf(u, 1, n) {
			int mn = 0x3f3f3f3f;
			nmf(v, 1, n) {
				if ((i & (1 << (v - 1)))) {
					mn = min(mn, dis[u][v]);
				}
			}
			mx = max(mx, mn);
		}
		ans = min(ans, mx);
	}
	cout << ans << endl;
}
signed main() {
#ifndef LOCAL
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> c >> T;
	while (T--)
		solve();
	cerr << "Time Used : " << clock() * (1000.0 / CLOCKS_PER_SEC) << " ms." << endl;
}