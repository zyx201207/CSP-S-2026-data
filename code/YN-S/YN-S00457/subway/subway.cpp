#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct str {
	int u, w;
};
int a[500505], dist[500505], vis[500505];
int qd, zd;
int id, n, m, d, q;
vector<str> g[500505];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void distl(int s) {
	for (int i = 0; i <= m + 500; i++)
		dist[i] = INT_MAX, vis[i] = 0;
	while (!pq.empty())
		pq.pop();
	pq.push({0, s});
	while (!pq.empty()) {
		auto top = pq.top();
		int w = top.first, u = top.second;
		if (u == zd)
			return;
		vis[u] = 1;
		for (auto it : g[u]) {
			if (vis[it.u] == 0 && it.w + w <= dist[it.u]) {
				dist[it.u] = it.w + w;
				pq.push({it.w + w, it.u});
			}
		}
		pq.pop();
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> id >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i + 500];
	}
	for (int i = 1; i <= n; i++) {
		int zs;
		cin >> zs;
		for (int j = 1; j <= zs; j++) {
			int u, w;
			cin >> u >> w;
			g[i].push_back({u + 500, w});
			g[u + 500].push_back({i, w});
		}
	}
	for (int T = 1; T <= q; T++) {
		cin >> qd >> zd;
		qd += 500, zd += 500;
		distl(qd);
		cout << dist[zd] + a[qd] + a[zd] << "\n";
	}
	return 0;
}
