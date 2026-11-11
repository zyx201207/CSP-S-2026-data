#include <bits/stdc++.h>

using namespace std;

/*

*/

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef unsigned long long ULL;

const int N = 2e5 + 10;
const int INF = 1e9;

int n, k;
int w[100][100];
vector<int> nodes;
int res = INF;
int fa[100], dist[100], cur_dist[100];

int find(int x) {
	if (x == fa[x]) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
	return find(x) == find(y);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}

void dfs(int u, int fa, int d) {
	dist[u] = d;
	for (int v = 1; v <= n; v++) {
		if (v != fa && w[u][v]) {
			dfs(v, u, d + 1);
		}
	}
}

void check() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < nodes.size(); i++) {
		for (int j = i + 1; j < nodes.size(); j++) {
			int u = nodes[i], v = nodes[j];
			merge(u, v);
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < nodes.size(); i++) {
		int u = nodes[i];
		if (u == find(u)) {
			cnt++;
		}
	}
	
	if (cnt > 2 || cnt == 0) {
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		dist[i] = 100;
	}
	for (auto v : nodes) {
		dist[v] = 0;
	}
	
	for (auto u : nodes) {
		for (int i = 1; i <= n; i++) {
			cur_dist[i] = 100;
		}
		dfs(u, 0, 0);
		for (int i = 1; i <= n; i++) {
			dist[i] = min(dist[i], cur_dist[i]);
		}
	}
	
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dist[i]);
	}
	res = min(res, mx - 1);
}

void choose(int u) {
	if (u == n + 1) {
		if (nodes.size() != k) {
			return;
		}
		check();
		return;
	}
	
	nodes.push_back(u);
	choose(u + 1);
	nodes.pop_back();
	choose(u + 1);
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			w[i][j] = 0;
		}
	}
	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		w[u][v] = 1;
		w[v][u] = 1;
	}
	
	res = INF;
	choose(1);
	cout << res << "\n";
}

int main() {
	#ifndef LOCAL_TEST
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1, c;
	cin >> c >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
} 
