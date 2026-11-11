#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+5;
struct edge {
	ll to, id;
};
struct node {
	ll w, u, id;
	const bool operator >(const node &Y) const {
		return w > Y.w;
	}
};
vector<edge> to[maxn];
priority_queue<node, vector<node>, greater<node> > pq;
ll c, n, m, d, q;
ll dis[maxn], k[maxn], x[maxn], y[maxn], w[maxn];
map<pair<ll, ll>, ll> t;
map<pair<ll, ll>, ll> vis;
//t[{i, j}]代表i站站厅到j线的路程长度 
vector<ll> xian[maxn];
ll dijkstra(ll st, ll ed) {
	vis.clear();
	memset(dis, 0x3f, sizeof dis);
	while (!pq.empty()) pq.pop();
	for (ll it : xian[st]) {
		pq.push({t[{st, it}], st, it});
	}
	ll ans = 1e18;
	while (!pq.empty()) {
		node cur = pq.top(); pq.pop();
		if (vis.count({cur.u, cur.id}) && vis[{cur.u, cur.id}] <= cur.w) {
			continue;
		}
		vis[{cur.u, cur.id}] = cur.w;
		if (cur.u == ed) {
			ans = min(ans, cur.w + t[{cur.u, cur.id}]);
		}
		for (edge e : to[cur.u]) {
			if (e.id == cur.id) {
				dis[e.to] = cur.w;
				pq.push({dis[e.to], e.to, e.id});
			} else {
				ll d = cur.w + t[{cur.u, cur.id}] + t[{cur.u, e.id}];
				if (dis[e.to] > d) {
					dis[e.to] = d;
				}
				pq.push({d, e.to, e.id});
			}
		}
	}
	return ans;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x[j] >> y[j];
			t[{x[j], i}] = y[j];
			xian[x[j]].push_back(i);
		}
		for (int j = 1; j < k[i]; j++) {
			to[x[j]].push_back({x[j+1], i});
			to[x[j+1]].push_back({x[j], i});
		}
	}
	for (int i = 1; i <= q; i++) {
		ll u, v; cin >> u >> v;
		cout << w[u] + w[v] + dijkstra(u, v) << '\n';
	}
	return 0;
}
