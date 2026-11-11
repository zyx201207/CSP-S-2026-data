#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005;
int taskid, n, m, d, q, book[N][N], dis[N][N];
int w[N];
vector<pair<int, int> >e[N];

void add(int a, int b, int c) {
	e[a].push_back({b, c});
	e[b].push_back({a, c});
}

inline int read() {
	int f = 1, r = 0;
	char c;
	c = getchar();
	while (c < '0' || c > '9')
		f = -1, c = getchar();
	while (c >= '0' && c <= '9')
		r = r * 10 + c - '0', c = getchar();
	return f * r;
}

void dijkstra(int s) {
	priority_queue<pair<int, int> >q;
	dis[s][s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (book[s][u])
			continue;
		book[s][u] = 1;
		for (auto i : e[u]) {
			int v = i.first, w = i.second;
			if (dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				q.push({-dis[s][v], v});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	taskid = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
		w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k;
		k = read();
		for (int j = 1; j <= k; j++) {
			int t1, t2;
			t1 = read(), t2 = read();
			add(m + i, t1, t2);
		}
	}
	for (int i = 1; i <= m; i++)
		dijkstra(i);
	while (q--) {
		int s, t;
		s = read(), t = read();
//		dijkstra(s);
		cout << dis[s][t] + w[s] + w[t] << '\n';
	}
	return 0;
}