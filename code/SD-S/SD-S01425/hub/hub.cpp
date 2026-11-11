#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3010;
int c, n, k, f[N], dist[N], ans, is[N], d[N];
vector<int> e[N];
queue<int> q;

inline void dfs(int u, int fa) {
	dfn[++cnt] = u;
	d[u] = cnt;
	for (auto v : e[u]) if (v != fa) {
		f[v] = u;
		dfs(v, u);
	}
}

int dfs2(int i, int c) {
	if (i == n + 1) {
		q = queue<int>();
		for (int l = 1; l <= n; l++) 
			dist[l] = 1 << 30;
		for (int i = 1; i <= n; i++) 
			if (is[i]) 
				q.push(dfn[i]), dist[dfn[i]] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto y : e[x]) 
				if (dist[y] > dist[x] + 1) {
					dist[y] = dist[x] + 1;
					q.push(y);
				}
		}
		int res = 0;
		for (int l = 1; l <= n; l++) 
			res = max(res, dist[l]);
		ans = min(ans, res);
		return;
	}
	if (is[d[f[dfn[i]]]]) {
		is[i] = 1;
		dfs(i + 1, c);
	} else if (c < 2) {
		is[i] = 1;
		dfs(i + 1, c + 1);
	}
	is[i] = 0;
	dfs(i + 1, c);
}

inline void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) 
		e[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	ans = 1 << 30;
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			q = queue<int>();
			for (int l = 1; l <= n; l++) 
				dist[l] = 1 << 30;
			q.push(i);
			dist[i] = 0;
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				for (auto y : e[x]) 
					if (dist[y] > dist[x] + 1) {
						dist[y] = dist[x] + 1;
						q.push(y);
					}
			}
			int res = 0;
			for (int l = 1; l <= n; l++) 
				res = max(res, dist[l]);
			ans = min(ans, res);
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int t;
	scanf("%d%d", &c, &t);
	while (t--) {
		solve();
	}
}

