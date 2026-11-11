#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

void init() { // 拜托，多测要清空
	
}

vector<int> adj[MAXN];

int n, k, fa[MAXN];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void init(int n) {
	for (int i = 1; i <= n; ++i) fa[i] = i;	
}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return ;
	fa[x] = y;
}

int f[MAXN][21], dep[MAXN];

void dfs(int u, int fa) {
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (int i = 1; i <= 20; ++i) f[u][i] = f[f[u][i - 1]][i - 1];
	
	for (auto v : adj[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (u == v) return u;
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; ~i; --i) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
	if (u == v) return u;
	for (int i = 20; ~i; --i) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int dis(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];	
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) adj[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v; 
			cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		dfs(1, 0);
		int ans = 1e9;
		if (n <= 10) {
			for (int S = 0; S < (1 << n); ++S) {
				if (__builtin_popcount(S) != k) continue;
				vector<int> node;
				for (int i = 0; i < n; ++i) {
					if (S >> i & 1) { 
						node.emplace_back(i + 1);
					}
				}
				init(n);
				for (auto u : node) {
					for (auto v : adj[u]) {
						if (S >> (v - 1) & 1) {
							merge(u, v);
						}
					}
				}
				vector<int> anc;
				for (auto u : node) {
					anc.emplace_back(find(u));
				}
				sort(anc.begin(), anc.end());
				anc.erase(unique(anc.begin(), anc.end()), anc.end());
				if (anc.size() > 2) continue;
				int mxd = 0;
				for (int i = 1; i <= n; ++i) {
					int mnd = 1e9;
					for (auto u : node) {
						mnd = min(mnd, dis(u, i));
					}
					mxd = max(mxd, mnd);
				}
				ans = min(ans, mxd);
			}
			cout << ans << '\n';
		}
//		else if (k <= 2) {
//			for (int u = 1; u <= n; ++u) {
//				
//			}
//			for (int u = 1; u <= n; ++u) {
//				for (int v = 1; v <= n; ++v) {
//					
//				}
//			}
//		}
	}
	return 0;
}
/*
空间开够 / 开大了吗
需要卡常吗
还剩多少时间
*/