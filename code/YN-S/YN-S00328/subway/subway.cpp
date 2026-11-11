#include <bits/stdc++.h>
using namespace std;
const int N = 550005;
int c, n, m, d, Q, w[N];
int head[N], nex[N << 1], ver[N << 1], edge[N << 1], tot = 1;

struct node {
	int d, u;
	bool operator<(const node &rhs) const {
		return d > rhs.d;
	}
};

void addEdge(int u, int v, int w) {
	ver[++tot] = v, edge[tot] = w, nex[tot] = head[u], head[u] = tot;
	ver[++tot] = u, edge[tot] = w, nex[tot] = head[v], head[v] = tot;
}

int calc(int x, int y) {
	static int dis[N], vis[N];
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	dis[x] = 0;
	q.push(node {0, x});
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (u == y)
			return dis[u];
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = nex[i]) {
			int v = ver[i], w = edge[i];
			if (!vis[v] && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(node {dis[v], v});
			}
		}
	}
	return -1;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k, a, t;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a >> t;
			addEdge(a, i + m, t);
		}
	}
	while (Q--) {
		int x, y;
		cin >> x >> y;
		cout << (calc(x, y) + w[x] + w[y]) << '\n';
	}
	return 0;
}