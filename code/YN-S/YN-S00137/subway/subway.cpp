#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 5;
const ll inf = 1e18;
ll c, n, m, d, que;

struct edge {
	ll v, w;
};
vector<edge> e[N];
ll w[N];
ll a[N], t[N];

struct node {
	ll u, dis;
	friend operator<(node r, node rhs) {
		return rhs.dis > r.dis;
	}
};

ll dis[N];

priority_queue<node> q;

void dj(ll s, ll t) {
	for (ll i = 1; i <= m; i++) {
		dis[i] = inf;
	}
	dis[s] = 0;
	q.push({s, 0});
	//cout << s;
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		ll u = now.u, d = now.dis;
		//cout << now.u << ' ';
		if (dis[u] < d) {
			continue;
		}
		for (auto it : e[u]) {
			ll v = it.v, w = it.w;
			//cout << v << ' ';
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;

				q.push({v, dis[v]});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> que;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (ll u = 1; u <= k; u++) {
			for (ll v = u + 1; v <= k; v++) {
				e[a[u]].push_back({a[v], t[u] + t[v]});
				e[a[v]].push_back({a[u], t[u] + t[v]});
			}
		}
	}

	for (ll i = 1; i <= que; i++) {
		ll x, y;
		cin >> x >> y;
		//cout << x;
		dj(x, y);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}

