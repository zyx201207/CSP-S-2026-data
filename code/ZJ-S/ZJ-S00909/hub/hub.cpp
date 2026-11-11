#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int c, t, n, k, ch[maxn], ic[maxn], dsufa[maxn], hm[maxn];
int fa[11][maxn], dep[maxn], ans;
vector <int> G[maxn];
pair <int, int> e[maxn];
void initdsu() {
	for (int i = 1; i <= n; i++)
		dsufa[i] = i;
}
int find(int x) {
	return dsufa[x] == x ? x : dsufa[x] = find(dsufa[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y)
		dsufa[x] = y;
}
void dfsg(int u, int f) {
	dep[u] = dep[f] + 1;
	fa[0][u] = f;
	for (int i = 1; i <= 10; i++)
		fa[i][u] = fa[i - 1][fa[i - 1][u]];
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v != f)
			dfsg(v, u);
	}
}
int LCA(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 10; i >= 0; i--)
		if (dep[fa[i][x]] >= dep[y])
			x = fa[i][x];
	if (x == y)
		return x;
	for (int i = 10; i >= 0; i--)
		if (fa[i][x] != fa[i][y])
			x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}
int dist(int x, int y) {
	return (dep[x] - 1) + (dep[y] - 1) - 2 * (dep[LCA(x, y)] - 1);
}
int d(int x) {
	int res = INT_MAX;
	for (int i = 1; i <= k; i++)
		res = min(res, dist(x, ch[i]));
	return res;
}
void dfs(int pos) {
	if (pos == k + 1) {
		memset(hm, 0, (n + 1) * 4);
		initdsu();
		for (int i = 1; i < n; i++) {
			int u = e[i].first, v = e[i].second;
			if (ic[u] && ic[v])
				merge(u, v);
		}
		for (int i = 1; i <= k; i++)
			hm[find(ch[i])] = 1;
		int tmp = 0;
		for (int i = 1; i <= n; i++)
			tmp += hm[i];
		if (tmp > 2)
			return ;
		int r = 0;
		for (int i = 1; i <= n; i++)
			r = max(r, d(i));
		ans = min(ans, r);
		return ;
	}
	for (int i = ch[pos - 1] + 1; i <= n; i++) {
		ch[pos] = i;
		ic[i] = 1;
		dfs(pos + 1);
		ic[i] = 0;
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = INT_MAX;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			e[i] = {u, v};
		}
		dfsg(1, 0);
		dfs(1);
		cout << ans << "\n";
	}
}
