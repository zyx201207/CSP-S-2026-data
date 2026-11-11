#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1000007;
vector<int> g[N];
int fa[N], dep[N];
struct DSU {
	int fa[N];
	void init(int _n) {
		for (int i = 1; i <= _n; ++i)
			fa[i] = i;
	}
	int Find(int x) {
		return fa[x]==x ? x : fa[x]=Find(fa[x]);
	}
	void Merge(int u, int v) {
		u = Find(u), v = Find(v);
		if (u != v)
			fa[u] = v;
	}
} D;
void dfs(int u) {
	for (int v : g[u]) {
		if (v == fa[u])
			continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}
int dis(int u, int v) {
	int d = 0;
	while (u != v) {
		if (dep[u] > dep[v]) {
			++d;
			u = fa[u];
		}
		else {
			++d;
			v = fa[v];
		}
	}
	return d;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int testidx, T;
	scanf("%d%d", &testidx, &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i)
			g[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		int ans = n-1;
		for (int mask = 0; mask < (1<<n); ++mask) {
			if (__builtin_popcount(mask) != k)
				continue;
			D.init(n);
			for (int u = 0; u < n; ++u) {
				if ((mask>>u) & 1) {
					for (int v : g[u+1])
						if ((mask>>(v-1)) & 1)
							D.Merge(u+1, v);
				}
			}
			int cc = 0;
			for (int u = 0; u < n; ++u)
				if ((mask>>u) & 1)
					cc += (D.Find(u+1)==(u+1));
			if (cc > 2)
				continue;
			int x = 0;
			for (int u = 1; u <= n; ++u) {
				int y = n-1;
				for (int v = 0; v < n; ++v)
					if ((mask>>v) & 1)
						y = min(y, dis(u, v+1));
				x = max(x, y);
				if (x >= ans)
					break;
			}
			ans = min(ans, x);
		}
		printf("%d\n", ans);
	}
	return 0;
}
