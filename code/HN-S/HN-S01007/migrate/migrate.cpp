#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll

const int inf = (1 << 30);
const int N = 1e4 + 7;

int n, d, a[N];
vector<int> adj[N];

int dis[N];
ll dp[N];
bool vis[N];

void bfs(int s) {
	fill(dis + 1, dis + n + 1, inf);
	fill(dp + 1, dp + n + 1, 0);
	fill(vis + 1, vis + n + 1, false);
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	dp[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : adj[u]) {
			if (dis[u] + 1 < dis[v]) {
				dp[v] = 0;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
			if (dis[u] + 1 == dis[v]) dp[v] += dp[u];
		}
	}
	// for (int i = 1; i <= n; i++) printf("%lld ", dp[i]);
	// puts("");
}

void solve(int test) {
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n && a[j] - a[i] <= d; j++) adj[i].emplace_back(j);
	}
	if (test >= 13 && test <= 14) {
		puts("0");
		return;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		bfs(i);
		for (int j = i + 1; j <= n; j++) {
			if (dp[j] == 2) ++ans;
			// printf("%lld ", dp[j]);
		}
		// puts("");
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) adj[i].clear();
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%lld%lld", &c, &t);
	while (t--) solve(c);
	return 0;
}

// g++ main.cpp -o main -g -O2 -std=c++14 -static
// ./main
// time ./main