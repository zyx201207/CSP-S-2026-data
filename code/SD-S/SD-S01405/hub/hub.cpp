#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1E6 + 10;

int c, t;
int n, m;
vector<int> tree[N];
int dist[15][15];
int dp[N], dia;

void dfs(int u, int fa) {
	for (int v : tree[u]) {
		if (v == fa) continue;
		dfs(v, u);
		dia = max(dia, dp[u] + dp[v] + 1); 
		dp[u] = max(dp[u], dp[v] + 1);
	}
}

void solve() {
	cin >> n >> m, dia = 0;
	
	if (c <= 3) {
		memset(dist, 0x3f, sizeof dist);
		for (int i = 0; i < n; i ++) dist[i][i] = 0;
		vector<pair<int, int>> E;
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			E.emplace_back(u, v);
			dist[u][v] = dist[v][u] = 1;
		}
		for (int k = 0; k < n; k ++)
			for (int i = 0; i < n; i ++)
				for (int j = 0; j < n; j ++)
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
		
		int res = 1 << 30;
		for (int i = 0; i < 1 << n; i ++) {
			if (__builtin_popcount(i) != m) continue;
			int mx = 0, cnt = m;
			for (auto t : E) {
				int u = t.first, v = t.second;
				if ((i >> u & 1) && (i >> v & 1))
					cnt --;
			}
			if (cnt > 2) continue;
			for (int j = 0; j < n; j ++) {
				int mn = 1 << 30;
				for (int k = 0; k < n; k ++)
					if (i >> k & 1) mn = min(mn, dist[j][k]);
				mx = max(mx, mn);
			}
			res = min(res, mx);
		}
		
		cout << res << '\n';
	} else {
		memset(dp, 0, 4 * (n + 1));
		for (int i = 1; i <= n; i ++)
			tree[i].clear();
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		dfs(1, -1);
		
		cout << (dia + m) / (m + 1) << '\n';
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> c >> t;
	
	while (t -- ) solve();
	
	return 0;
}
