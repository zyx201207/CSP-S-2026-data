#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 5e5 + 5, INF = 1e16;

struct Edge {
	int nxt;
	int val;
};

struct Point {
	int id;
	int val;
	friend bool operator < (Point a, Point b) {
		return a.val > b.val;
	}
};
int c, n, m, d, tot;
int num[M];
int siz[N];
vector<int> id[M], tim[M];
vector<Edge> edge[N];
int dis[N][N];
bool sure[N][N];

void diskjstra(int s) {
	priority_queue<Point> q;
	for (int i = 1; i <= n; i++)
		dis[s][i] = INF;
	dis[s][s] = 0;
	q.push({s, 0});
	while (!q.empty()) {
		int cur = q.top().id;
		q.pop();
		sure[s][cur] = 1;
		while (!q.empty() && sure[s][q.top().id])
			q.pop();
		for (Edge side : edge[cur]) {
			if (dis[s][cur] + side.val < dis[s][side.nxt]) {
				dis[s][side.nxt] = dis[s][cur] + side.val;
				q.push({side.nxt, dis[s][side.nxt]});
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
	cin >> c >> n >> m >> d >> tot;
	for (int i = 1; i <= m; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		cin >> siz[i];
		int pos, t;
		for (int j = 1; j <= siz[i]; j++) {
			cin >> pos >> t;
			id[pos].push_back(i);
			tim[pos].push_back(t);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < id[i].size(); j++) {
			for (int k = j + 1; k < id[i].size(); k++) {
				edge[id[i][j]].push_back({id[i][k], tim[i][j] + tim[i][k]});
				edge[id[i][k]].push_back({id[i][j], tim[i][j] + tim[i][k]});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		diskjstra(i);
	int u, v;
	for (int i = 1; i <= tot; i++) {
		cin >> u >> v;
		int ans = INF;
		for (int j = 0; j < id[u].size(); j++)
			for (int k = 0; k < id[v].size(); k++)
				ans = min(ans, num[u] + num[v] + tim[u][j] + tim[v][k] + dis[id[u][j]][id[v][k]]);
		cout << ans << '\n';
	}
	return 0;
}