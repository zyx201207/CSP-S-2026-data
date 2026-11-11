#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int dist[N], INF = 0x3f3f3f3f;
bool st[N];
vector <pair<int, int>> g[N];

int d(int start, int end) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start] = 0;
	pq.push({0, start});
	while (pq.size()) {
		auto [v, u] = pq.top();
		pq.pop();
		if (st[u]) {
			continue;
		}
		st[u] = 1;
		for (int i = 0; i < g[u].size(); i++) {
			if (dist[g[u][i].first] > dist[u] + g[u][i].second) {
				dist[g[u][i].first] = dist[u] + g[u][i].second;
				pq.push({dist[u] + g[u][i].second, g[u][i].first});
			}
		}
	}
	if (dist[end] == INF) {
		return -1;
	}
	return dist[end];
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back({y, z});
	}
	cout << d(1, n);
	return 0;
}
