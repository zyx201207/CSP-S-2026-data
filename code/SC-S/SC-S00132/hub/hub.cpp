#include"bits/stdc++.h"
using namespace std;
const int N = 1e6 + 5;
int c, t, n, k;
vector<int>g[N];
bool adj[1005][1005];
int ans;
bool cho[1005];
struct DSU {
	vector<int>pa, size;
	DSU (int n) {
		pa.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 1; i <= n; i++)
			pa[i] = i;
	}
	int find(int x) {
		return pa[x] == x ? x : pa[x] = find(pa[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)
			return;
		if (size[x] < size[y])
			swap(x, y);
		size[x] += size[y];
		pa[y] = x;
	}
};
int check() {
	DSU dsu(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && cho[i] && cho[j] && adj[i][j])
				dsu.unite(i, j);
	set<int>pa;
	for (int i = 1; i <= n; i++)
		if (cho[i])
			pa.insert(dsu.find(i));
	if (pa.size() > 2)
		return 0x3f3f3f;
	int re = 0;
	for (int i = 1; i <= n; i++) {
		vector<int>d(n + 1, 0x3f3f3f3f);
		d[i] = 0;
		queue<int>q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : g[u]) {
				if (d[v] > d[u] + 1) {
					d[v] = d[u] + 1;
					if (cho[v]) {
						re = max(re, d[v]);
						break;
					}
					q.push(v);
				}
			}
		}
	}
	return re;
}
void dfs(int ind, int cnt) {
	if (ind > n) {
		if (cnt == k)
			ans = min(ans, check());
		return;
	}
	if (cnt + (n - ind + 1) < k || cnt > k)
		return;
	cho[ind] = 1;
	dfs(ind + 1, cnt + 1);
	cho[ind] = 0;
	dfs(ind + 1, cnt);
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			g[i].clear(), memset(adj[i], 0, sizeof adj[i]);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			adj[u][v] = adj[v][u] = 1;
		}
		if (k == 2) {
			int ans = 0x3f3f3f3f;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					if (i == j)
						continue;
					vector<int>di(n + 1, 0x3f3f3f3f), dj(n + 1, 0x3f3f3f3f);
					di[i] = dj[j] = 0;
					queue<int>q;
					q.push(i);
					while (!q.empty()) {
						int u = q.front();
						q.pop();
						for (int v : g[u])
							if (di[v] > di[u] + 1) {
								di[v] = di[u] + 1;
								q.push(v);
							}
					}
					q.push(j);
					while (!q.empty()) {
						int u = q.front();
						q.pop();
						for (int v : g[u])
							if (dj[v] > dj[u] + 1) {
								dj[v] = dj[u] + 1;
								q.push(v);
							}
					}
					int cur = 0;
					for (int k = 1; k <= n; k++)
						if (k != i && k != j)
							cur = max(cur, min(di[k], dj[k]));
					ans = min(ans, cur);
				}
			cout << ans << '\n';
			continue;
		}
		ans = 0x3f3f3f3f;
		dfs(1, 0);
//		cho[1] = cho[4] = 1;
//		cout << check() << ' ';
		cout << ans << '\n';
	}
	return 0;
}