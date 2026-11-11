#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 6e5 + 5;

struct node {
	ll id, val;
};
ll it, n, m, d, p, cost[N], dis[N];
bool vis[N];
vector<node> e[N];

struct edge {
	ll id, val;
	friend bool operator<(edge a, edge b) {
		return a.val > b.val;
	}
};
priority_queue<edge> q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> it >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++)
		cin >> cost[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll u, w;
			cin >> u >> w;
			e[u].push_back({m + i, w});
			e[m + i].push_back({u, w});
		}
	}
	for (int j = 1; j <= p; j++) {
		ll s, t;
		cin >> s >> t;
		for (int i = 1; i <= n + m; i++) {
			dis[i] = 1e18;
			vis[i] = 0;
		}
		q.push({s, 0});
		dis[s] = 0;
		while (!q.empty()) {
			int u = q.top().id;
			q.pop();
			if (vis[u])
				continue;
			vis[u] = 1;
			for (int i = 0; i < e[u].size(); i++) {
				int v = e[u][i].id, w = e[u][i].val;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					if (!vis[v])
						q.push({v, dis[v]});
				}
			}
		}
		cout << dis[t] + cost[s] + cost[t] << '\n';
	}
	return 0;
}