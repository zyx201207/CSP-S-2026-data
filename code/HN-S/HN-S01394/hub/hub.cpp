#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int N = 1000005;
int c, T, n, k, dist[N], f[N][21], id[N];
vector<int> edges[N];
set<int> a, b;
llong ans;
void dfs(int u) {
	for (auto v : edges[u])
		if (dist[v] == -1) {
			dist[v] = dist[u] + 1;
			f[v][0] = u;
			dfs(v);
		}
}
int LCA(int u, int v) {
	if (dist[u] < dist[v])
		swap(u, v);
	int x = dist[u] - dist[v];
	for (int i = 0; x > 0; x /= 2, i++)
		if (x % 2 == 1)
			u = f[u][i];
	if (u == v)
		return u;
	for (int i = 20; i >= 0; i--)
		if (f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}
int dis(int u, int v) {
	return dist[u] + dist[v] - dist[LCA(u, v)] * 2;
}
void dfs2(int x, int s) {
	if (x == n + 1) {
		if (s != k)
			return;
		a.clear();
		b.clear();
		for (int i = 1; i <= k; i++)
			for (auto j : edges[id[i]])
				if (a.count(j) || a.empty())
					a.insert(id[i]);
				else if (b.count(j) || b.empty())
					b.insert(id[i]);
				else
					return;
		llong res = 0;
		for (int i = 1; i <= n; i++) {
			int mi = 1 << 30;
			for (int j = 1; j <= k;	j++)
				mi = min(mi, dis(i, id[j]));
			res += mi;
		}
		ans = min(ans, res);
		return;
	}
	if (s < k) {
		id[s + 1] = x;
		dfs2(x + 1, s + 1);
	}
	dfs2(x + 1, s);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for (int i = 1; i <= n; i--)
			dist[i] = -1;
		dist[1] = 0;
		dfs(1);
		for (int j = 1; j <= 20; j++)
			for (int i = 1; i <= n; i++)
				f[i][j] = f[f[i][j - 1]][j - 1];
		ans = 1LL << 60LL;
		dfs2(1, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
