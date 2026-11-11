//
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define N 35

int c, T, n, k, u, v, d[N], fa[N], dis[N][N], a[N], t[N];
bool flag[N][N];

vector<int> g[N];

void dfs(int u, int f) {
	d[u] = d[f] + 1, fa[u] = f;
	for (auto x : g[u]) {
		if (x != f) {
			dfs(x, u);
		}
	}
}

int fun(int x) {
	return (t[x] == x ? x : t[x] = fun(t[x]));
}

void DFS(int k, int cur, int l) {
	if (k == cur) {
		for (int i = 1; i <= n; i++) t[i] = i;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				
			}
		}
	} else {
		for (int i = l + 1; i <= n; i++) {
			a[cur + 1] = i;
			DFS(k, cur + 1, i);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			flag[u][v] = flag[v][u] = true;
		}
		dfs(1, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int x = i, y = j, idx;
				if (d[x] > d[y]) swap(x, y);
				while (d[x] != d[y]) y = fa[y];
				if (x == y) idx = x;
				else {
					while (fa[x] != fa[y]) x = fa[x], y = fa[y];
					idx = fa[x];
				}
				dis[i][j] = d[i] + d[j] - 2 * d[idx];
			}
		}
		
	}
	return 0;
}
