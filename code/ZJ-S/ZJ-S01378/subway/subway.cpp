#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

const ll N = 5e5 + 5;
const ll inf = numeric_limits<ll>::max() / 100;

// Vars
ll c, n, m, d, q;
ll w[N];
ll dis[505][505];
ll line_switch_t[505][505];

struct route {
	ll line_ind, t;
};

vector<ll> line_to_sta[505]; // 从第 i 条线路可以去的地铁站
unordered_map<ll, vector<route>> to_line; // 从第 i 个地铁站去第 j 条线路所需时间

struct node {
	ll now, val;
	bool operator > (const node other) const {
		return val > other.val;
	}
};

void Dijkstra(ll s) {
	// 初始化
	for (ll i = 1; i <= n; i++) dis[s][i] = inf;

	priority_queue<node, vector<node>, greater<node>> que;	
	dis[s][s] = 0;
	que.push({s, 0});

	while (que.size()) {
		auto now = que.top();
		que.pop();

		if (dis[s][now.now] < now.val) continue;

		for (ll i = 1; i <= n; i++) {
			if (dis[s][i] > line_switch_t[now.now][i] + now.val) {
				dis[s][i] = line_switch_t[now.now][i] + now.val;
				que.push({i, dis[s][i]});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll tk; cin >> tk;
		for (ll k = 1; k <= tk; k++) {
			ll a, t;
			cin >> a >> t;

			// 从 a 号地铁站到第 i 条线路所需时间 t
			to_line[a].push_back({i, t});
			line_to_sta[i].push_back(a);
		}
	}

	// 预处理第 i 条地铁线路 到 第 j 条地铁线路的中转最小时间
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			line_switch_t[i][j] = inf;
		}
	}
	// 单次换乘
	for (ll i = 1; i <= m; i++) {
		// i 是地铁站编号
		for (auto j : to_line[i]) {
			for (auto k : to_line[i]) {
				if (j.line_ind == k.line_ind) continue;

				line_switch_t[j.line_ind][k.line_ind] = min(
					line_switch_t[j.line_ind][k.line_ind],
					j.t + k.t
				);
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		line_switch_t[i][i] = 0;
	}

	// Dijkstra 全源最短路
	for (ll i = 1; i <= n; i++) {
		Dijkstra(i);
	}

	while (q--) {
		ll x, y;
		cin >> x >> y;
		
		ll mid_ans = inf;
		for (auto i : to_line[x]) {
			for (auto j : to_line[y]) {
				mid_ans = min(mid_ans, dis[i.line_ind][j.line_ind] + i.t + j.t);
			}
		}

		cout << w[x] + mid_ans + w[y] << "\n";
	}
	fflush(stdout);

	return 0;
}
