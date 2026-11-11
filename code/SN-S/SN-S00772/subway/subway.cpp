#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10;
#define pii pair<int, int>

int c, n, m, d, q;

inline int read() {
	char ch = getchar();
	int ans = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

int w[M];
vector<pii> tmp[M], g[M];
int k; 
int dis[M], vis[M];
void solve(int st) {
	for (int i = 1; i <= m; i++) dis[i] = 0x3f;
	for (int i = 1; i <= m; i++) vis[i] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	dis[st] = 0; vis[st] = 1;
	pq.push({0, st});
	while (pq.size()) {
		int u = pq.top().second, t = pq.top().first;
		pq.pop();
		if (dis[u] < t) continue;
		int len = g[u].size();
		for (int i = 0; i < len; i++) {
			int v = g[u][i].first, w = g[u][i].second;
			
			if (w + dis[u] < dis[v]) {
				dis[v] = w + dis[u];
				pq.push({dis[v], v});
			}
		}
	}
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();

	int x = 0, y = 0;
	for (int st = 1; st <= n; st++) {
		k = read();
		for (int i = 1; i <= k; i++) {
			x = read(), y = read();
			tmp[i].push_back({x, y});
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int leni = tmp[i].size();
		for (int j = 0; j < leni; j++) {
			pii a = tmp[i][j];
			int u = a.first, d1 = a.second;
			for (int k = 0; k < leni; k++) {
				pii b = tmp[i][k];
				int v = b.first, d2 = b.second;
				g[u].push_back({v, d1 + d2});
				g[v].push_back({u, d1 + d2});
			}
		}
	}

	while (q--) {
		int st, ed;
		st = read(), ed = read();
		solve(st);
		cout << dis[ed] + w[st] + w[ed] << '\n';
	}
	return 0;
}
