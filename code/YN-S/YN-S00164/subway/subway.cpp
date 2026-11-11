#include <bits/stdc++.h>
using namespace std;
long long n, m, TTT, d, q;
const int N = 5e3 + 10;
long long in[N];

struct node {
	long long v, w;
};
vector<node>e[N];

long long dis[N];
bool vis[N];

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<pair<long long, int>>q;
	dis[s] = 0;
	q.push({0, s});
	while (q.size()) {
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		for (int i = 0; i < e[x].size(); i++) {
			long long v = e[x][i].v, w = e[x][i].w;
			if (dis[v] > dis[x] + w) {
				dis[v] = dis[x] + w;
				q.push({-dis[v], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> TTT;
	cin >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
	}
	for (int i = 1; i <= m; i++) {
		long long k, x1, t1, x2, t2;
		cin >> k >> x1 >> t1 >> x2 >> t2;
		e[x1].push_back({x2, t1 + t2});
		e[x2].push_back({x1, t1 + t2});
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y] + in[x] + in[y] << "\n";
	}

	return 0;
}
