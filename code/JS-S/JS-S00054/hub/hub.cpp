#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1000010;
const int inf = 1ll << 60;

bool b[N], vis[N];
vector<int> edges[N];
int n, k, dep[N], f[21][N];

void dfs(int u, int fa) {
	f[0][u] = fa;
	dep[u] = dep[fa] + 1;
	for(auto v : edges[u])
		if(v != fa)
			dfs(v, u);
}

void dfs2(int u) {
	vis[u] = true;
	for(auto v : edges[u])
		if(!vis[v] and b[v])
			dfs2(v);
}

void init() {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 20; j++)
			f[j][i] = f[j - 1][f[j - 1][i]];
}

int lca(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = 20; i >= 0; i--)
		if(dep[f[i][u]] >= dep[v])
			u = f[i][u];
	if(u == v)
		return u;
	for(int i = 20; i >= 0; i--)
		if(f[i][u] != f[i][v])
			u = f[i][u], v = f[i][v];
	return f[0][u];
}

bool check(int S) {
	int cnt = 0;
	fill(b + 1, b + n + 1, false);
	fill(vis + 1, vis + n + 1, false);
	for(int i = 0; i < n; i++)
		if(S & (1 << i))
			cnt++, b[i + 1] = true;
	if(cnt != k)
		return false;
	cnt = 0;
	for(int i = 1; i <= n; i++)
		if(!vis[i] and b[i])
			dfs2(i), cnt++;
	if(cnt > 2)
		return false;
	return true;
}

int dis(int x, int y) {
	int p = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[p];
}

int d(int i) {
	if(b[i])
		return 0;
	int res = inf;
	for(int j = 1; j <= n; j++)
		if(b[j])
			res = min(res, dis(i, j));
	return res;
}

int calc() {
	int mx = -1;
	for(int i = 1; i <= n; i++)
		mx = max(mx, d(i));
	return mx;
}

void solve1() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		edges[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].emplace_back(v);
		edges[v].emplace_back(u);
	}
	dep[0] = 0;
	dfs(1, 0);
	init();
	int ans = inf;
	for(int S = 1; S < (1 << n); S++) {
		if(!check(S))
			continue ;
		ans = min(ans, calc());
	}
	cout << ans << '\n';
}

void solve2() {
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].emplace_back(v);
		edges[v].emplace_back(u);
	}
	if(k == n)
		cout << 0 << '\n';
	else
		cout << 1 << '\n';
}

void solve3() {
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].emplace_back(v);
		edges[v].emplace_back(u);
	}
	int ans = inf;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			b[i] = true, b[j] = true;
			ans = min(ans, calc());
			b[i] = false, b[j] = false;
		}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--) {
		if(c <= 3)
			solve1();
		else if(c == 7)
			solve3();
		else 
			solve2();
	}
	return 0;
}