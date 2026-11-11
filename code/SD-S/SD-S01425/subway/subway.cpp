#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501000;
int c, n, m, d, query, w[N], ct[510][510];
bool vis[N];
vector<pair<int, int>> st[N], e[510];
ll dist[510];
priority_queue<pair<ll, int>> q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &query);
	for (int i = 1; i <= m; i++) 
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int x, t;
			scanf("%d%d", &x, &t);
			st[x].push_back(make_pair(i, t));
		}
	}
	for (int i = 1; i <= m; i++) {
		int sz = st[i].size();
		for (int j = 0; j < sz; j++) 
			for (int k = j + 1; k < sz; k++) {
				int idj = st[i][j].first, idk = st[i][k].first;
				int t = st[i][j].second + st[i][k].second;
				if (!ct[idj][idk]) 
					ct[idj][idk] = ct[idk][idj] = t;
				else 
					ct[idj][idk] = ct[idk][idj] = min(ct[idj][idk], t);
			}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			if (i != j && ct[i][j]) 
				e[i].push_back(make_pair(j, ct[i][j]));
	while (query--) {
		int u, v;
		scanf("%d%d", &u, &v);
		for (auto i : st[u]) 
			e[n + 1].push_back(i);
		for (auto i : st[v]) 
			e[i.first].push_back(make_pair(n + 2, i.second));
		for (int i = 1; i <= n + 2; i++) {
			dist[i] = 1ll << 60;
			vis[i] = 0;
		}
		dist[n + 1] = 0;
		q = priority_queue<pair<ll, int>>();
		q.push(make_pair(0, n + 1));
		while (!q.empty()) {
			int x = q.top().second;
			q.pop();
			if (vis[x]) 
				continue;
			vis[x] = 1;
			if (vis[n + 2]) 
				break;
			for (auto y : e[x]) 
				if (dist[y.first] > dist[x] + y.second) {
					dist[y.first] = dist[x] + y.second;
					q.push(make_pair(-dist[y.first], y.first));
				}
		}
		printf("%lld\n", dist[n + 2] + w[u] + w[v]);
		e[n + 1].clear();
		for (int i = 1; i <= n; i++) 
			if (e[i].back().first == n + 2) 
				e[i].pop_back();
	}
}

