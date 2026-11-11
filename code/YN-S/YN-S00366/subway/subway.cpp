#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
const int N = 510;
const int M = 5e5 + 10;
int c, n, m, d, Q;
int k[N], w[M], dis[N][N], vis[N][N];

struct point {
	int id, tim;
};

struct edge {
	int v, w;
};

struct node {
	int v, w;
	friend bool operator<(node a, node b) {
		return a.w > b.w;
	}
};
vector<edge>e[N];
vector<point>bel[M];
//vector<point>t[M];
priority_queue<node>q;

void dij(int sta) {
	dis[sta][sta] = 0;

	while (!q.empty())
		q.pop();
	q.push({sta, 0});

	while (!q.empty()) {
		node now = q.top();
		int u = now.v;
		q.pop();

		if (vis[sta][u])
			continue;
		vis[sta][u] = 1;

		for (auto g : e[u]) {
			int v = g.v, w = g.w;

			if (dis[sta][v] >= dis[sta][u] + w) {
				dis[sta][v] = dis[sta][u] + w;

				if (!vis[sta][v])
					q.push({v, dis[sta][v]});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> Q;

	for (int i = 1; i <= m; i++)

		cin >> w[i];

	for (int i = 1; i <= n; i++) {

		cin >> k[i];

		for (int j = 1; j <= k[i]; j++) {

			int poi, tim;
			cin >> poi >> tim;
			bel[poi].push_back({i, tim});
//			t[i].push_back(tim);
		}
	}

	for (int i = 1; i <= m; i++) {

		if (bel[i].size() <= 1)
			continue;

		for (auto it1 : bel[i]) {
			int u = it1.id, wt = it1.tim;

			for (auto it2 : bel[i]) {
				int v = it2.id, wb = it2.tim;

				if (u == v)
					continue;
				int w = wt + wb;
				e[u].push_back({v, w});
//				e[v].push_back({u, w});
//				cout << "u:" << u << " v:" << v << " w:" << w << "\n";
			}
		}
	}

	memset(dis, 0x3f, sizeof dis);

	for (int i = 1; i <= n; i++) {

		dij(i);
	}

//	for (int i = 1; i <= n; i++) {
//
//		for (int j = 1; j <= n; j++) {
//
//			cout << dis[i][j] << " ";
//		}
//
//		cout << "\n";
//	}

	while (Q--) {
		int st, ed;
		cin >> st >> ed;
		int base = w[st] + w[ed];
		int res = INF;

		for (auto it1 : bel[st]) {
			int u = it1.id, wt = it1.tim;

			for (auto it2 : bel[ed]) {
				int v = it2.id, wb = it2.tim;
				res = min(res, base + wt + wb + dis[u][v]);
			}
		}

		cout << res << "\n";
	}

	return 0;
}