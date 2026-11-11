#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> PIII;
const int M = 5e5 + 10;
int c, n, m, d, Q, w[M], dis[M], t[510][M], ans[M];
bool f[M];
priority_queue <PIII, vector<PIII>, greater<PIII>> q;

struct Node {
	int from, to, next, idx;
} a[M * 20];
int pre[M], k;

struct quest {
	int s, e;
} que[100010];

void add(int u, int v, int idx) {
	a[++k] = {u, v, pre[u], idx};
	pre[u] = k;
}

bool cmp(quest x, quest y) {
	return x.s < y.s;
}

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(f, false, sizeof(f));
	q.push({0, {s, 0}});
	dis[s] = 0;
	while (!q.empty()) {
		PIII h = q.top();
		q.pop();
		int u = h.second.first, id = h.second.second;
		if (f[u] == true)
			continue;
		f[u] = true;
		for (int i = pre[u]; i; i = a[i].next) {
			int to = a[i].to, idx = a[i].idx;
			if (f[to] == true)
				continue;
			if (id == 0) {
				if (dis[u] + t[idx][u] < dis[to]) {
					dis[to] = dis[u] + t[idx][u];
					q.push({dis[to], {to, idx}});
				}
			} else {
				if (idx == id) {
					if (dis[u] < dis[to]) {
						dis[to] = dis[u];
						q.push({dis[to], {to, idx}});
					}
				} else {
					if (dis[u] + t[id][u] + t[idx][u] < dis[to]) {
						dis[to] = dis[u] + t[id][u] + t[idx][u];
						q.push({dis[to], {to, idx}});
					}
				}
			}
		}
		ans[u] = dis[u] + t[id][u];
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.ans", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &Q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		int u, v;
		scanf("%d", &u);
		scanf("%d", &t[i][u]);
		for (int j = 2; j <= x ; j++) {
			scanf("%d", &v);
			add(u, v, i);
			u = v;
			scanf("%d", &t[i][u]);
		}
	}
	for (int i = 1; i <= Q; i++) {
		scanf("%d %d", &que[i].s, &que[i].e);
	}
	sort(que + 1, que + Q + 1, cmp);
	for (int i = 1; i <= Q; i++) {
		int s = que[i].s, e = que[i].e;
		if (s != que[i - 1].s) {
			dijkstra(s);
			printf("%d\n", ans[e] + w[s] + w[e]);
		} else
			printf("%d\n", ans[e] + w[s] + w[e]);
	}
	return 0;
}
