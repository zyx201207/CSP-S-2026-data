#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3e6 + 7;
ll c, t;
ll n, d;
ll x[N];

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
	for (ll i = 0; i < N; ++i) {
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

bool ok[N];

ll bfs(ll s, ll t) {
	queue<rec > que;
	que.push({s, 0});
	ll cnt = 0;
	ok[s] = true;
	while (!que.empty()) {
		rec tmp = que.front();
		que.pop();
		ok[tmp.x] = false;
		if (tmp.x == t && tmp.t == dis[t]) {
			++cnt;
			continue;
		}
		for (ll nxt = head[tmp.x]; nxt; nxt = nd[nxt].nxt) {
			ll v = nd[nxt].ed;
			if (!ok[v]) {
				que.push({v, tmp.t + v});
				ok[v] = true;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		if (c >= 11 && c <= 12) {
			ll tp = abs(x[2] - x[1]);
			if (tp > d) {
				cout << 0 << '\n';
			} else {
				
			}
			continue;
		}
		for (ll i = 1; i <= n; ++i) {
			for (ll j = i + 1; j <= n; ++j) {
				if (x[j] - x[i] <= d) {
					add_edge(x[i], x[j], 1);
					add_edge(x[j], x[i], 1);
				}
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= n; ++i) {
			dijk(x[i]);
			for (ll j = i + 1; j <= n; ++j) {
				ll ct = bfs(x[i], x[j]);
				if (ct == 2) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}