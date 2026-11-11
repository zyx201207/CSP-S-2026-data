#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

const ll N = 1e6 + 5;
const ll inf = numeric_limits<ll>::max() / 100;

// Vars
ll c, t;
ll n, k;
ll d1, d2;

ll fa[N];
bool if_is[N], vis[N];

vector<ll> edges[N];
vector<ll> longest_route;

void init() {
	longest_route.clear();
	for (ll i = 1; i <= n; i++) {
		edges[i].clear();
		fa[i] = i;
	}
}

ll find(ll x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(ll x, ll y) {
	ll fx = find(x), fy = find(y);
	if (fx == fy) return;
	fa[fx] = fy;
}

vector<ll> this_route;
void dfs(ll now, ll father) {
	if (vis[now]) return;
	vis[now] = true;

	this_route.push_back(now);
	if (this_route.size() > longest_route.size()) {
		longest_route = this_route;
	}
	for (auto i : edges[now]) {
		if (i != father) dfs(i, now);
	}
	this_route.pop_back();
}

vector<ll> get_h_dots(ll now, ll father) {
	vector<ll> res;
	for (auto i : edges[now]) {
		if (now == father) continue;
		vector<ll> t_res = get_h_dots(i, now);
		for (auto j : t_res) res.push_back(j);
	}
	return res;
}

void add_one(ll now) {
	vector<ll> h_dots = get_h_dots(now, 0);
	vector<ll> min_l;

	for (auto i : h_dots) {
		if_is[i] = true;
		fill(vis, vis + n + 1, 0);
		vis[d1] = vis[d2] = true;
		for (auto to : edges[d1]) dfs(to, 0);

		if (longest_route.size() > min_l.size()) {
			min_l = longest_route;
		}
	}

	if_is[*min_l.begin()] = true;
}

void update() {
	vector<ll> this_longest_path1, this_longest_path2;
	
	fill(vis, vis + n + 1, 0);
	vis[d2] = true;
	dfs(d1, 0);
	this_longest_path1 = longest_route;

	fill(vis, vis + n + 1, 0);
	vis[d1] = true;
	dfs(d2, 0);
	this_longest_path2 = longest_route;

	if (this_longest_path1.size() > this_longest_path2.size()) {
		add_one(d1);
	}
	else {
		add_one(d2);
	}
}

ll get_this_dis(ll now, ll father) {
	ll res = inf;
	if (if_is[now]) res = 0;
	for (auto i : edges[now]) {
		if (i == father) continue;
		res = min(res, get_this_dis(i, now) + 1);
	}
	return res;
}

ll calc() {
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		if (if_is[i]) continue;
		res = max(res, get_this_dis(i, 0));
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> c >> t;
	while (t--) {
		init();

		cin >> n >> k;
		for (ll i = 1; i < n; i++) {
			ll u, v;
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		if (k >= n) {
			cout << 0 << endl;
			continue;
		}

		// 构造贪心
		dfs(1, 0);
		ll root = *longest_route.rbegin();
		dfs(root, 0);
		
		if (k == 1) {
			cout << longest_route.size() / 2;
			continue;
		}

		d1 = longest_route[longest_route.size() * 1 / 4];
		d2 = longest_route[longest_route.size() * 3 / 4];
		if_is[d1] = if_is[d2] = true;
		k -= 2;

		while (k) {
			update();
			k--;
		}

		cout << calc() << endl;
	}

	return 0;
}
