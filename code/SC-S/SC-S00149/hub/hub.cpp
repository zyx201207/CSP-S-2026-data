
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> g[N];
int c, T, n, k;

namespace task3 {
	const int M = 20;
	int vis[M], dis[M], fa[N];
	int fd(int x) {
		if (fa[x] == x)	return x;
		return fa[x] = fd(fa[x]);
	}
	void calc() {
		int ans = 1e9;
		for (int i = 0; i < (1 << n); ++i) {
			memset(vis, 0, sizeof vis);
			memset(dis, 0, sizeof dis);
			int sum = 0, now = 0;
			for (int j = 1; j <= n; ++j) {
				if ((i >> (j - 1)) & 1) {
					sum++, vis[j] = 1;
				}
				fa[j] = j;
			}
			if (sum != k)	continue;
			queue<int> q;
			for (int j = 1; j <= n; ++j) {
				if (vis[j]) {
					q.push(j);
					for (int kk : g[j]) {
						if (vis[kk])	fa[fd(j)] = fd(kk);
					}
				}
			}
			int cnt = 0;
			for (int j = 1; j <= n; ++j) {
				if (vis[j] && fa[j] == j)	cnt++;
			}
			if (cnt > 2)	continue;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				now = max(now, dis[u]);
				for (int v : g[u]) {
					if (!vis[v]) {
						vis[v] = 1;
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			ans = min(ans, now);
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
		}
		for (int i = 1, u, v; i < n; ++i) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		task3::calc();
	}
	return 0;
}
