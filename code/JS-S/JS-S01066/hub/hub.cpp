#include <bits/stdc++.h>
#define ll long long
const int N = 12;
using namespace std;

bool vis[N];
int n, k, dis[N];
vector <int> g[N];

void dfs(int u, int i) {
	for(int v : g[u]) {
		if(((i >> (v - 1)) & 1) && !vis[v]) {
			vis[v] = true;
			dfs(v, i);
		}
	}
}

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();

	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if(n <= 10) {
		int ans = 100;
		for(int i = 0; i < (1 << n); i++) {
			int num = 0;
			for(int j = 0; j < n; j++) {
				num += ((i >> j) & 1);
			}
			if(num != k) continue;

			for(int j = 1; j <= n; j++) vis[j] = false;
			
			num = 0;
			for(int j = 1; j <= n; j++) {
				if(((i >> (j - 1)) & 1) && !vis[j]) {
					dfs(j, i);
					num++;
				}
			}

			if(num > 2) continue;

			queue <pair <int, int> > q;
			for(int j = 1; j <= n; j++) {
				vis[i] = false;
				dis[i] = 0;
				if(((i >> (j - 1)) & 1)) {
					q.push(make_pair(j, 0));
				}
			}

			while(q.size()) {
				int u = q.front().first;
				int step = q.front().second;
				q.pop();

				if(vis[u]) continue;
				vis[u] = true;
				dis[u] = step;

				for(int v : g[u]) {
					if(vis[v]) continue;
					q.push(make_pair(v, step + 1));
				}
			}

			int maxn = 0;
			for(int j = 1; j <= n; j++) maxn = max(maxn, dis[j]);

			ans = min(ans, maxn);
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--) solve();

	return 0;
}
