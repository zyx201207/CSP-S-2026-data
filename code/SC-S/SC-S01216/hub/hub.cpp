#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+5;
int c, T, n, k, ans;
vector<int> G[MAXN];
vector<pair<int, int>> E;
bool tag[MAXN];

struct DSU {
	int fa[MAXN], cnt;
	void init() {
		cnt = k;
		for (int i = 1; i <= n; i++)	fa[i] = i * tag[i];
	}
	int get(int x) {
		return fa[x] = fa[x] == x ? x : get(fa[x]);
	}
	bool merge(int x, int y) {
		int fax = get(x), fay = get(y);
		if (fax == fay)	return 0;
		cnt--, fa[fax] = fay;
		return 1;
	}
} dsu;



int check() {
	dsu.init();
	for (pair<int, int> e : E)
		if (tag[e.first] && tag[e.second])
			dsu.merge(e.first, e.second);
	return dsu.cnt;
}
bool vis[MAXN];
int bfs() {
	fill(vis + 1, vis + 1 + n, 0);
	int ans = 0;
	queue <pair<int, int>> q;
	for (int i = 1; i <= n; i++)
		if (tag[i])	q.push({i, 0}), vis[i] = 1;
	while (!q.empty()) {
		int cur = q.front().first, d = q.front().second;
		q.pop(), ans = max(ans, d);
		for (int nxt : G[cur]) {
			if (vis[nxt])	continue;
			q.push({nxt, d + 1}), vis[nxt] = 1;
		}
	}
	return ans;
}

void dfs(int x, int cnt) {
	if (cnt == k) {
		if (check() <= 2)	ans = min(ans, bfs());
		return;
	}
	if (n - x + 1 < k - cnt)	return;
	if (x > n)	return;
	dfs(x + 1, cnt);
	
	tag[x] = 1;
	dfs(x + 1, cnt + 1);
	tag[x] = 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		
		
		E.clear();
		for (int i = 1; i <= n; i++)	G[i].clear();
		
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			E.push_back({u, v});
		}
		ans = 1e18;
		
//		cout << check(1) << "\n";
		dfs(1, 0);
		cout << ans << "\n";
	}
	
	
	return 0;
}