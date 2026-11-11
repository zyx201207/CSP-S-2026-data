#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 510;
struct Line {
	ll v, w;
	bool operator> (const Line& rhs) const { return w > rhs.w; }
};
ll c, n, m, d, q, w[N], vis[N], ptr = 0;
vector<ll> dis;
vector<Line> g[N];
ll Dijkstra(int u, int v, ll k) {
	priority_queue<Line, vector<Line>, greater<Line>> pq;
	dis[u] = 0; pq.push({u, 0}); vis[u] = k;
	while (pq.size()) {
		Line line = pq.top(); pq.pop();
		ll u = line.v;
		vis[u] = k;
		for (Line l : g[u]) {
			ll v = l.v, w = l.w;
			if (vis[v] == k) continue;
			else if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
	return dis[v];
}
int main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> c >> m >> n >> d >> q; ptr = n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= m; i++) {
		ll k, a, t, lst = -1; cin >> k;
		ll Q,W;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			Q = ++ptr;
			if (j != 1) {
				g[Q].push_back({W, 0});
				g[W].push_back({Q, 0});
				lst = a;
			}
			g[a].push_back({Q, t});
			g[Q].push_back({a, t});
			W = Q;
		}
	}
	ll ans, lt, rt;
	for (int i = 1, k = 1; i <= q; i++, k++) {
		cin >> lt >> rt;
		dis = vector<ll>(ptr + 1, LLONG_MAX);
		ans = w[lt] + w[rt] + Dijkstra(lt, rt, k);
		cout << ans << '\n';
	}
	return 0;
}
