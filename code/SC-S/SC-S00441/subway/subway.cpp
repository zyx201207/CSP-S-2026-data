#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e7 + 7;
const ll M = 1e6 + 7;
ll c, n, m, d, q, w[M], tp[N], all;

struct edge {
	ll ed, nxt, t;
}nd[2 * N];
ll total;
ll head[N];

void add_edge(ll u, ll v, ll w) {
	++total;
	nd[total].t = w;
	nd[total].ed = v;
	nd[total].nxt = head[u];
	head[u] = total;
}

struct rec {
	ll x, t;
};

bool operator<(rec a, rec b) {
	return a.t > b.t;
}

ll dis[N];
bool flag[N];

void dijk(ll s) {
	for (ll i = 0; i <= all; ++i) {
		dis[i] = 1e9 + 7;
		flag[i] = false;
	}
	dis[s] = 0;
	priority_queue<rec > que;
	que.push({s, dis[s]});
	while (!que.empty()) {
		ll u = que.top().x;
		while (flag[u]) {
			que.pop();
			if (que.empty()) {
				break;
			}
			u = que.top().x;
		}
		if (que.empty()) {
			return ;
		}
		u = que.top().x;
		flag[u] = true;
		for (ll nxt = head[u]; nxt; nxt = nd[nxt].nxt) {
			ll v = nd[nxt].ed;
			if (dis[v] > dis[u] + nd[nxt].t) {
				dis[v] = dis[u] + nd[nxt].t;
				que.push({v, dis[v]});
			}
		}
	}
}

bool if_so[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (ll i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	
	for (ll i = 1; i <= n; ++i) {
		ll k;
		cin >> k;
		ll pre_end = 0;
		for (ll j = 1; j <= k; ++j) {
			ll a, t;
			cin >> a >> t;
			ll enda = a + m;
			while (if_so[enda]) {
				++enda;
			}
			if_so[enda] = true;
			add_edge(a, enda, t);
			add_edge(enda, a, t);
			if (j > 1) {
				add_edge(enda, pre_end, 0);
				add_edge(pre_end, enda, 0);
			}
			pre_end = enda;
			all = max(all, enda);
		}
	}
	
	while (q--) {
		ll x, y;
		cin >> x >> y;
		dijk(x);
		cout << (dis[y] + w[x] + w[y]) << '\n';
	}
	
	return 0;
}