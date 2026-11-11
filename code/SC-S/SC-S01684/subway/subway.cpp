#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 5e5 + 5;
const int maxm = 1e6 + 5;

// m 为地铁站数量，n 为线路数
int c, n, m, d, q, k, a, t, x, y, tot, w[maxn];
vector<pair<int, int>> G[maxn];
vector<pair<int, int>> p[maxn];
long long dis[maxm];
bool vis[maxm];
long long ans[maxn];

void Dijkstra(int s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		int o = ++tot + m;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			int x = ++tot + m;
			G[x].push_back({o, 0});
			G[o].push_back({x, 0});
			G[a].push_back({x, t});
			G[x].push_back({a, t});
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		ans[i] = 0LL + w[x] + w[y];
		if (x > y) swap(x, y);
		p[x].push_back({y, i});
	}

	for (int i = 1; i <= m; i++) {
		if (p[i].empty()) continue;
		Dijkstra(i);
		for (const auto& it : p[i]) {
			int y = it.first;
			int idx = it.second;
			ans[idx] += dis[y];
		}
	}

	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}

void Dijkstra(int s) {
	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>
	               > q;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	q.push({0, s});
	dis[s] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x]) continue;
		vis[x] = true;
		for (const auto& it : G[x]) {
			int y = it.first;
			int z = it.second;
			if (dis[y] > dis[x] + z) {
				dis[y] = dis[x] + z;
				q.push({dis[y], y});
			}
		}
	}
}