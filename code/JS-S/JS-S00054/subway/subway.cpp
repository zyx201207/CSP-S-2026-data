#include <bits/stdc++.h>
#define int long long

using namespace std;
using pll = pair<int, int>;
const int N = 1000010;
const int inf = 1ll << 60;

bool vis[N];
set<pll> pq;
vector<pll> edges[N];
vector<int> t[501], a[501];
int c, n, m, d, q, num, w[N], dist[N], k[N];

void addedge(const int u, const int v, const int w) {
	edges[u].emplace_back(v, w);
	edges[v].emplace_back(u, w);
}

int dijkstra(int s, int t) {
	fill(dist, dist + num + 1, inf);
	dist[s] = 0;
	pq.emplace(0, s);
	while(!pq.empty()) {
		int u = pq.begin() -> second;
		pq.erase(pq.begin());
		for(auto p : edges[u]) {
			int v = p.first, w = p.second;
			if(dist[v] > dist[u] + w) {
				pq.erase({dist[v], v});
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
	return dist[t];
}

void solve1() {
	for(int i = 1; i <= m; i++) 
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].emplace_back(0);
		t[i].emplace_back(0);
		for(int j = 1; j <= k[i]; j++) {
			int x, y;
			cin >> x >> y;
			a[i].emplace_back(x);
			t[i].emplace_back(y);
		}
	}
	num = m;
	for(int i = 1; i <= n; i++) {
		++num;
		addedge(num, a[i][1], t[i][1]);
		for(int j = 2; j <= k[i]; j++) {
			++num;
			addedge(num - 1, num, 0);
			addedge(num, a[i][j], t[i][j]);
		}
	}
	for(int i = 0; i < q; i++) {
		int s, t;
		cin >> s >> t;
		cout << (w[s] + w[t] + dijkstra(s, t)) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if(c >= 0 and c <= 8)
		solve1();
	return 0;
}