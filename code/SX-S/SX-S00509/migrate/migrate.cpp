#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX = 1<<29;
int testidx, T;
int n;
LL d;
LL a[2000007];
struct Graph {
	vector<int> g[2000007];
	int dis[2000007], way[2000007];
	void addE(int u, int v) {
		g[u].push_back(v);
	}
	void bfs(int Start) {
		for (int i = 1; i <= n; ++i) {
			dis[i] = MAX;
			way[i] = 1;
		}
		dis[Start] = 0;
		queue<int> que;
		que.push(Start);
		while (!que.empty()) {
			int u = que.front(); que.pop();
			if (way[u] == 3)
				continue;
			for (int v : g[u]) {
				if (dis[u]+1 < dis[v]) {
					que.push(v);
					dis[v] = dis[u]+1;
					way[v] = way[u];
				}
				else if (dis[u]+1 == dis[v])
					way[v] = min(way[v]+way[u], 3);
			}
		}
	}
} G;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &testidx, &T);
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", a + i);
			G.g[i].clear();
		}
		for (int i = 1; i <= n; ++i)
			for (int j = i+1; j <= n; ++j) {
				if (a[j]-a[i] <= d)
					G.addE(i, j);
				else
					break;
			}
		int ans = 0;
		for (int u = 1; u <= n; ++u) {
			G.bfs(u);
			for (int v = u+1; v <= n; ++v)
				ans += (G.way[v]==2);
		}
		printf("%d\n", ans);
	}
	return 0;
}
