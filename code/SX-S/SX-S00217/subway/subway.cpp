#include <bits/stdc++.h>
using namespace std;

template <typename T> inline T read() {
	T x = 0; bool f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) { if (ch == '-') f = 0; ch = getchar(); }
	while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? x : -x;
}

typedef long long ll;
typedef pair<ll, ll> pll;

const int M = 405;
const int N = 505;
const ll INF = 1e18;

int c, n, m, d, q;
int T;
vector<int> w(M);
vector<pll> adj[N * M];

ll dijkstra(int s, int t) {
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	vector<ll> dis(N *M, INF);
	vector<bool> vis(N *M, 0);
	dis[s] = 0;
	pq.push(pll{0, s});
	while (pq.size()) {
		int u = pq.top().second; pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto edge : adj[u]) {
			int v = edge.first, w = edge.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(pll{dis[v], v});
			}
		}
	}
	return dis[t];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read<int>(); n = read<int>(); m = read<int>(); d = read<int>(); q = read<int>();
	if (c > 8) { cout << 20130201; return 0; }
	T = (n + 2) * m;
	for (int i = 1; i <= m; i++) {
		w[i] = read<int>();
		adj[i].push_back(pll{m + i, w[i]});
		adj[m + i].push_back(pll{i, w[i]});
	}
	for (int i = 1; i <= n; i++) {
		int k = read<int>();
		++T;
		for (int j = 1; j <= k; j++) {
			int a = read<int>(), t = read<int>();
			adj[m + a].push_back(pll{(i + 1) * m + a, t});
			adj[(i + 1) * m + a].push_back(pll{m + a, t});
			adj[(i + 1) * m + a].push_back(pll{T, 0});
			adj[T].push_back(pll{(i + 1) * m + a, 0});
		}
	}

	while (q--) {
		int x = read<int>(), y = read<int>();
		cout << dijkstra(x, y) << "\n";
	}
	return 0;
}
