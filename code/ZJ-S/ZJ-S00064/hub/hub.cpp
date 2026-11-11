#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long INF = 1e17;
int c, t, n, k, vis[N], dis[N];
long long ans;
vector <int> p[N], ins;
queue <int> q;
bitset <N> b;
void dfs(int tl, int cnt) {
	if (cnt == k) {
		long long tot = 0;
		for (int j = 0; j < ins.size(); ++j) q.push(ins[j]);
		for (int i = 1; i <= n; ++i) dis[i] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			// cout << u << " " << dis[u] << "\n";
			for (int l = 0; l < p[u].size(); ++l) {
				int to = p[u][l];
				if (dis[to] || vis[to]) continue ;
				dis[to] = dis[u] + 1, q.push(to), tot = max(tot, (long long)dis[to]);
			}
		}
		if (tot < ans) ans = tot;
		return ;
	}
	b.reset();
	for (int j = 0; j < ins.size(); ++j) {
		int tu = ins[j];
		for (int i = 0; i < p[tu].size(); ++i) {
			int to = p[tu][i];
			b[to] = 1;
			if (!vis[to]) {
				vis[to] = 1, ins.push_back(to);
				dfs(tl, cnt + 1);
				vis[to] = 0, ins.pop_back();
			}
		}
	}
	if (!tl) {
		for (int i = 1; i <= n; ++i) 
			if (!b[i]) {
				vis[i] = 1, ins.push_back(i);
				dfs(1, cnt + 1);
				vis[i] = 0, ins.pop_back();
			}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &k), ans = INF;
		for (int i = 1; i <= n; ++i) dis[i] = 0, p[i].clear();
		for (int i = 1, u, v; i < n; ++i) {
			scanf("%d%d", &u, &v);
			p[u].push_back(v), p[v].push_back(u);
		}
		for (int i = 1; i <= n; ++i) {
			vis[i] = 1, ins.push_back(i);
			dfs(0, 1);
			vis[i] = 0, ins.pop_back();
		}
		printf("%lld\n", ans);
	}
	return 0;
}
