#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;
int c, n, m, d, q, cnt;
bool vis[22 * M];
long long ans[22 * M], awa[Q];
struct node {
	int to, w;
};
struct heap {
	int now;
	long long step;
	bool operator < (const heap &x) const {
		return step < x.step;
	}
};
struct question {
	int u, v, id;
	bool operator < (const question &x) const {
		return u < x.u;
	}
} qwq[Q];
vector <node> a[22 * M];
void dijkstra (int st) {
	for (int i = 1; i <= cnt; i++)
		ans[i] = LLONG_MAX, vis[i] = 0;
	ans[st] = 0;
	priority_queue <heap> q;
	q.push({st, 0});
	while (!q.empty()) {
		int u = q.top().now;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto tmp : a[u]) {
			int v = tmp.to, dis = tmp.w;
			if (ans[v] > ans[u] + dis) {
				ans[v] = ans[u] + dis;
				if (!vis[v])
					q.push({v, ans[v]});
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int tmp;
		cin >> tmp;
		a[i].emplace_back({m + i, tmp});
		a[m + i].emplace_back({i, tmp});
	}
	cnt = 2 * m;
	for (int i = 1; i <= n; i++) {
		int len, nxt = -1, now, t;
		cin >> len;
		for (int j = 1; j <= len; j++) {
			cin >> now >> t;
			int pos = ++cnt;
			if (nxt != -1) {
				a[pos].emplace_back({nxt, 0});
				a[nxt].emplace_back({pos, 0});
			}
			a[pos].emplace_back({m + now, t});
			a[m + now].emplace_back({pos, t});
			nxt = pos;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> qwq[i].u >> qwq[i].v;
		qwq[i].id = i;
	}
	sort (qwq + 1, qwq + q + 1);
	for (int i = 1; i <= q; i++) {
//		cout << qwq[i].u << ' ' << qwq[i].v << ' ' << qwq[i].id << ' ';
		if (qwq[i].u != qwq[i - 1].u || i == 1)
			dijkstra(qwq[i].u);
		awa[qwq[i].id] = ans[qwq[i].v];
	}
	for (int i = 1; i <= q; i++)
		cout << awa[i] << '\n';
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
