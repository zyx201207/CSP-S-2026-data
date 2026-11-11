#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int P = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 1e3 + 5;

int c;
int ans = INF;
int n, k;
int a[maxn];
int vis[maxn];
int u[maxn], v[maxn];
vector<int> g[maxn], G[maxn];

void dfss(int x, int fa, int co) {
	vis[x] = co;
	for (auto e : G[x]) {
		if (e == fa) continue;
		dfss(e, x, co);
	}
}

int lg[maxn];
int dep[maxn];
int dfn[maxn], dfnn;
int st[20][maxn];

void dfs2(int x, int fa) {
	dep[x] = dep[fa] + 1;
	dfn[x] = ++ dfnn, st[0][dfnn] = fa;
	for (auto e : g[x]) {
		if (e == fa) continue;
		dfs2(e, x);
	}
}
int get(int x, int y) {
	return dfn[x] < dfn[y];
}
int lca(int x, int y) {
	if (x == y) return x;
	if ((x = dfn[x]) > (y = dfn[y])) swap(x, y);
	int cc = lg[y - x ++];
	return get(st[cc][x], st[cc][y - (1 << cc) + 1]);
}
int dis(int x, int y) {
	return dep[x] + dep[y] - dep[lca(x, y)];
}

int b[maxn];
pair<int, int> eeee[maxn];

void dfs(int x) {
	if (x == n + 1) {
		int cnt = 0;
		for (int i = 1; i <= n; ++ i ) cnt += a[i], vis[i] = 0, G[i].clear(), g[i].clear();
		if (cnt != k) return ;
		for (int i = 1; i < n; ++ i ) {
			if (a[u[i]] == 1 && a[v[i]] == 1) {
				G[u[i]].push_back(v[i]), G[v[i]].push_back(u[i]);
			}
		}
		cnt = 0;
		for (int i = 1; i <= n; ++ i ) {
			if (a[i] == 0) continue;
			if (vis[i] == 0) {
//				cout << i << " " << cnt << endl;
				vis[i] = ++ cnt;
				if (cnt >= 3) return ;
				dfss(i, 0, cnt);
			}
		}
//		for (int i = 1; i <= n; ++ i ) cout << a[i] << " ";
//		cout << endl;
		int ccc = 0, cc = 0;
		for (int i = 1; i < n; ++ i ) {
			if (vis[u[i]] == vis[v[i]] && vis[u[i]] != 0) continue;
			if (vis[u[i]] < vis[v[i]]) swap(u[i], v[i]);
			if (vis[u[i]] == 1) eeee[++ ccc] = {n + 1, v[i]}, b[++ cc] = n + 1, b[++ cc] = v[i];
			if (vis[u[i]] == 2) eeee[++ ccc] = {n + 2, v[i]}, b[++ cc] = n + 2, b[++ cc] = v[i];
			if (vis[u[i]] == 0) eeee[++ ccc] = {u[i], v[i]}, b[++ cc] = u[i], b[++ cc] = v[i];
		}
		sort(b + 1, b + cc + 1);
		cc = unique(b + 1, b + cc + 1) - b - 1;
		for (int i = 1; i <= ccc; ++ i ) {
			int u = lower_bound(b + 1, b + cc + 1, eeee[i].first) - b;
			int v = lower_bound(b + 1, b + cc + 1, eeee[i].second) - b;
			g[u].push_back(v), g[v].push_back(u); 
		}
		dfs2(n + 1, 0);
		for (int i = 2; i <= cc; ++ i ) lg[i] = lg[i >> 1] + 1;
		for (int i = 1; i <= lg[cc]; ++ i ) {
			for (int j = 1; j + (1 << i) - 1 <= cc; ++ j ) {
				st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
		int maxx = 0;
		for (int i = 1; i <= n + cnt; ++ i ) {
			for (int j = 1; j <= n + cnt; ++ j ) {
				maxx = max(maxx, dis(i, j));
			}
		}
		ans = min(ans, maxx);
		return ;
	}
	a[x] = 1;
	dfs(x + 1);
	a[x] = 0;
	dfs(x + 1);
}

void work() {
	cin >> n >> k;
	ans = INF;
	for (int i = 1; i < n; ++ i ) {
		cin >> u[i] >> v[i];
	}
	dfs(1);
	cout << ans << endl;
}

signed main() {
//	system("fc hub2.ans hub.out");
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	fst;
	
	int t; cin >> c >> t;
	while (t -- ) {
		work();
	}
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
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

0 1
5 2
1 2
2 3
3 4
4 5

*/
