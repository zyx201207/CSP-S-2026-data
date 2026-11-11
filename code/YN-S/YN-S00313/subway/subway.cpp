#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, maxm = 5e5 + 5;
int c, n, m, d, q;
int cnt = 0;
int w[maxm];
int dis[maxm];
bool vis[maxm];

struct Edge {
	int y, w;
	Edge(int y, int w): y(y), w(w) {}
	bool operator <( Edge b) const {
		return w > b.w;
	}
};
vector<Edge> g[maxn];

void add(int x, int y, int w) {
	g[x].push_back(Edge(y, w));
	g[y].push_back(Edge(x, w));
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	cnt = m + 1;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a, t;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			add(a, cnt, t);
			if (j > 1)
				add(cnt, cnt - 1, 0);
			cnt++;
		}
	}
	while (q--) {
		for (int i = 1; i <= cnt; i++) {
			vis[i] = 0;
			dis[i] = 1e9 + 5;
		}
		int s, t;
		cin >> s >> t;
		priority_queue<Edge> q;
		q.push(Edge(s, 0));
		dis[s] = 0;
		while (q.size()) {
			int x = q.top().y;
			q.pop();
			if (vis[x])
				continue;
			vis[x] = 1;
			for (Edge node : g[x]) {
				int y = node.y, w = node.w;
				if (vis[y])
					continue;
				if (dis[x] + w < dis[y]) {
					dis[y] = dis[x] + w;
					q.push(Edge(y, dis[y]));

				}
			}
		}
		cout << dis[t] + w[s] + w[t] << endl;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}