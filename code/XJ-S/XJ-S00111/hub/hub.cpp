#include <bits/stdc++.h>
using namespace std;

const int N = 1000011;
int c, n, k, b[11], dist[11], ans;
vector<int> edges[N]; 
bool vis[11];
set<int> v;

inline void calc(int x) {
	vis[x] = true;
	for (auto y : edges[x]) {
		if (!vis[y] && v.count(y))
			calc(y);
	}
}

inline void dfs(int i, int num) {
	if (i == n + 1) {
		if (num != k) return;
		v.clear();
		for (int j = 1; j <= n; j++) {
			if (b[j]) v.insert(j);
		}
		for (int j = 1; j <= n; j++) vis[j] = false;
		int sum = 0;
		for (auto x : v) {
			if (vis[x]) continue;
			++sum, calc(x);
		}
		if (sum > 2) return;
		for (int j = 1; j <= n; j++) dist[j] = -1;
		queue<int> q;
		for (int j = 1; j <= n; j++) {
			if (b[j])
				dist[j] = 0, q.push(j); 
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto y : edges[x]) {
				if (dist[y] == -1) {
					dist[y] = dist[x] + 1;
					q.push(y);
				}
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			cnt = max(cnt, dist[j]);
		ans = min(ans, cnt);
		return;
	}
	b[i] = 0;
	dfs(i + 1, num);
	b[i] = 1;
	dfs(i + 1, num + 1);
}

inline void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) edges[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	if (c <= 3) {
		memset(b, 0, sizeof(b));
		ans = 1 << 30;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int test;
	scanf("%d%d", &c, &test);
	while (test--) {
		solve();
	}
	return 0;	
}
