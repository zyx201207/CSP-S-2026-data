#include <bits/stdc++.h>

using namespace std;
const int SZ = 5e5 + 5e3;
const long long INF = 1e18;

struct Edge {
	int to;
	long long w;
	
	Edge (int a, long long b) : to(a), w(b) {}
	
	bool operator< (const Edge& Oth) const {
		return w > Oth.w;
	}
};

int c, n, m, d, q;
long long a[SZ];
vector<Edge> adj[SZ];

int qq[SZ], hh, tt;
long long dist[SZ];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x; 
		cin >> x;
		int u = i + m;
		while (x--) {
			int v;
			long long w;
			cin >> v >> w;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}
	}
	
	while (q--) {
		int fr, to;
		cin >> fr >> to;
		
		for (int i = 1; i <= n + m; i++) dist[i] = INF;
		dist[fr] = 0;
		if (12 <= c && c <= 19) {
			hh = tt = 0;
			qq[tt++] = fr;
			while (hh != tt) {
				int u = qq[hh++];
				if (u == to) break;
				for (Edge ed : adj[u]) {
					int v = ed.to;
					long long w = ed.w;
					if (dist[u] + w < dist[v]) {
						dist[v] = dist[u] + w;
						qq[tt++] = v;
					}
				}
			}
		} else {
			priority_queue<Edge> pq;
			pq.emplace(fr, 0);
			while (!pq.empty()) {
				int u = pq.top().to;
				int ds = pq.top().w;
				pq.pop();
				if (ds != dist[u]) continue;
				if (u == to) break;
				for (Edge ed : adj[u]) {
					int v = ed.to;
					long long w = ed.w;
					if (dist[u] + w < dist[v]) {
						dist[v] = dist[u] + w;
						pq.emplace(v, dist[v]);
					}
				}
			}
		}
		cout << a[fr] + dist[to] + a[to] << '\n';
	}

	return 0;
}
