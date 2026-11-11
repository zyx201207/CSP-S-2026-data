#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 10;
const int inf = 2e18;

int n, k, osu[MAXN];
vector<int> adj[MAXN];

int find(int x) {
	return x == osu[x] ? x : osu[x] = find(osu[x]);
}

bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return false;
	osu[fx] = fy;
	return true; 
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) adj[i].clear();
	for (int i = 1; i < n; i ++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	int ans = inf;
	for (int mask = 0; mask < (1 << n); mask ++) {
		int sum = 0;
		for (int i = 0; i < n; i ++) sum += ((mask >> i) & 1);
		if (sum != k) continue;
		iota(osu + 1, osu + n + 1, 1);
		for (int i = 0; i < n; i ++) {
			int u = i + 1;
			if ((mask >> i) & 1) {
				for (int v : adj[u]) if ((mask >> (v - 1)) & 1) sum -= merge(u, v);
			}
		}
		if (sum > 2) continue;
		queue<int> q;
		vector<int> dis(n + 2, inf);
		vector<bool> vis(n + 2, false); 
		for (int i = 0; i < n; i ++) {
			if ((mask >> i) & 1) {
				dis[i + 1] = 0;
				q.push(i + 1);
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (int v : adj[u]) {
				if (dis[v] > dis[u] + 1) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		int cur = 0;
		for (int i = 1; i <= n; i ++) cur = max(cur, dis[i]);
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int C, T; cin >> C >> T;
	while (T --) solve();
}

/*
不能在代码注释里写小作文 
*/
