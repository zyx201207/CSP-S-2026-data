#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c, n, m, d, qp, val[N], a[510][2], st, en, ans, vis[N];
int head[N], num = 0;
int dist[N];

struct edg {
	int nxt, to, w;
} edge[N * 2];

void add(int from, int to, int w) {
	edge[++num].nxt = head[from];
	edge[num].to = to;
	edge[num].w = w;
	head[from] = num;
}
queue<int> q;

void dij(int x) {
	dist[x] = 0;
	q.push(x);
	vis[x] = 1;
	int v;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = head[v]; i != 0; i = edge[i].nxt) {
			if (dist[edge[i].to] > dist[v] + edge[i].w && !vis[edge[i].to]) {
				dist[edge[i].to] = dist[v] + edge[i].w;
				q.push(edge[i].to);
				vis[edge[i].to] = 1;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> qp;
	for (int i = 1; i <= m; i++)
		cin >> val[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> a[j][0] >> a[j][1];
		for (int j = 1; j < k; j++) {
			for (int l = j + 1; l <= k; l++) {
				add(a[j][0], a[l][0], a[j][1] + a[l][1]);
				add(a[l][0], a[j][0], a[j][1] + a[l][1]);
			}
		}
	}
	while (qp--) {
		memset(vis, 0, sizeof(vis));
		memset(dist, 0x7f, sizeof(dist));
		cin >> st >> en;
		dij(st);
		cout << dist[en] + val[st] + val[en] << '\n';
	}
	return 0;
}
