#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int c, n, m, d, qq, a[N], dis[N], vis[N];

struct node {
	int v, w;
};
vector<node> G[N];

void dij(int st) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[st] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, st});
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto x : G[u]) {
			int vv = x.v, ww = x.w;
			if (dis[u] + ww < dis[vv]) {
				dis[vv] = dis[u] + ww;
				q.push({dis[vv], vv});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int op;
		cin >> op;
		for (int j = 1; j <= op; j++) {
			int x, t;
			cin >> x >> t;
			G[i + m].push_back({x, t});
			G[x].push_back({i + m, t});
		}
	}
	while (qq--) {
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << a[x] + a[y] + dis[y] << "\n";
	}
	return 0;
}