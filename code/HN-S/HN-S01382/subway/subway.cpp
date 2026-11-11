#include <bits/stdc++.h>
using namespace std;
const int MAXM = 5e5 + 5;
const int MAXN = 505;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w;
};
int c, n, m, d, q;
int W[MAXM];
vector<Edge> G[MAXN + MAXM];

bool vis[MAXN + MAXM];
int dist[MAXN + MAXM];
struct Node {
	int u, cost;
	bool operator <(const Node& arg) const {
		return cost > arg.cost;
	}
};
priority_queue<Node> pq;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> W[i];
	}

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			G[m + i].push_back({a, t});
			G[a].push_back({m + i, t});
		}
	}
	
	while (q--) {
		int s, t;
		cin >> s >> t;
		while (!pq.empty()) pq.pop();
		for (int i = 1; i < MAXN + MAXM; i++) {
			dist[i] = INF;
			vis[i] = false;
		}
		
		pq.push({s, 0});
		dist[s] = 0;
		
		while (!pq.empty()) {
			Node cur = pq.top();
			pq.pop();
			int u = cur.u;
			
			if (vis[u]) continue;
			vis[u] = 1;
			
			for (const Edge& e : G[u]) {
				int v = e.v;
				int w = e.w;
				
				if (cur.cost + w < dist[v]) {
					dist[v] = cur.cost + w;
					pq.push({v, dist[v]});
				}
			}
		}
		
		cout << 1ll * dist[t] + 1ll * W[s] + 1ll * W[t] << '\n';
	}
	return 0;
} 
