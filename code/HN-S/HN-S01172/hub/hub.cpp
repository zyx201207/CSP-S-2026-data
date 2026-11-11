#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int c, t, n, k, dep[N], fa[N], dp[N][21], in[N], out[N];
vector<int> nbr[N];
bool vis[N];

int Calc(int x) {
	int cnt = 0;
	while (x) {
		if (x % 2 == 1)
			cnt++;
		x /= 2;
	}
	return cnt;
}

int Find(int x) {
	return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}

void Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x != y)
		fa[x] = y;
}

int ans = 2e9;

//int Lca(int u, int v) {
//	cout << "getlca:" << u << ' ' << v << '\n';
//	if (dep[u] < dep[v])
//		swap(u, v);
//	int tmpu = u;
//	for (int i = 19; i >= 1; i--) {
//		if (dep[dp[u][i]] >= dep[v])
//			u = dp[u][i];
//	}
//	if (u == v) {
////		cout << tmpu << '\n';
//		return u;
//	}
//	for (int i = 19; i >= 1; i--)
//		if (dp[u][i] != dp[v][i])
//			u = dp[u][i], v = dp[v][i];
//	cout << "Lca:" << u << ' ' << v << ' ' << dp[u][0] << '\n';
//	return dp[u][0]; 
//}

int Lca(int u, int v) {
	int maxn = 0, id = 1;
	for (int i = 1; i <= n; i++) {
		if ((in[i] <= in[u] && out[i] >= out[u]) && (in[i] <= in[v] && out[i] >= out[v])) {
			if (dep[i] > maxn)
				maxn = dep[i], id = i;
		}
	}
	return id;
}

int Check() {
	vector<int> nodes;
	for (int i = 1; i <= n; i++) 
		fa[i] = i;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			nodes.push_back(i);
			for (int v : nbr[i])
				if (dep[v] > dep[i])
					Union(v, i);
		}
	}
	if (nodes.size() < k)
		return 2e9;
	int cnt = 0;
	for (int u : nodes) {
		if (Find(u) == u) {
			cnt++;
		}
		if (cnt > 2) {
			return 2e9;
		}
	}
	int maxn = -2e9;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		int Min = 2e9;
		for (int j : nodes) {
//			cout << j << ' ';
			int lca = Lca(i, j);
			int dis = dep[i] + dep[j] - 2 * dep[lca];
			Min = min(Min, dis);
		}
		maxn = max(maxn, Min);
		if (maxn > ans)
			return 2e9;
	} 
	return maxn;
}

void dfs(int u, int cnt) {
//	if ((k) > (n - u + 1))
//		return;
	if (u > n + 1)
		return;
	if (cnt == k) {
		ans = min(ans, Check());
		return;
	}
	vis[u] = 1;
	dfs(u + 1, cnt + 1);
	vis[u] = 0;
	dfs(u + 1, cnt);
	return;
}

int tim;

void Init(int u, int fa) {
	in[u] = ++tim;
	dep[u] = dep[fa] + 1;
	dp[u][0] = fa;
	for (int i = 20; i >= 1; i--)
		dp[u][i] = dp[dp[u][i - 1]][i - 1];
	for (int v : nbr[u]) {
		if (v == fa)
			continue;
		Init(v, u);
	} 
	out[u] = tim;
}

void Solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		nbr[i].clear(), vis[i] = 0;
	ans = 2e9;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		nbr[u].push_back(v);
		nbr[v].push_back(u);
	} 
	Init(1, 0);
	dfs(1, 0);
	cout << ans << '\n';
} 

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
		Solve();
	return 0;
}

/*

0 1
5 2
1 2
2 3
3 4
4 5

*/

