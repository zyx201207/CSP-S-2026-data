#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];

struct edge {
	int to;
	int dis;
};
int dis[500507];
vector<edge> head[500507];

void add_edge(int i, int a, int t) {
	i = m + i;
	head[i].push_back((edge) {
		a, t
	});
	head[a].push_back((edge) {
		i, t
	});
}

struct node {
	int dis;
	int pos;
};

struct cmp {
	bool operator()(const node a, const node b) {
		return a.dis > b.dis;
	}
};
int vis[500507];

int dijistra(int start, int end) {
	priority_queue<node, vector<node>, cmp> qu;
	dis[start] = 0;
	qu.push((node) {
		0, start
	});
	while (!qu.empty()) {
		node tmp = qu.top();
		qu.pop();
		int x = tmp.pos;
		if (vis[x])
			break;
		vis[x] = 1;
		for (int i = 0; i < (int)head[x].size(); i++) {
			int y = head[x][i].to;
			int ww = head[x][i].dis;
			if (dis[y] >= dis[x] + ww) {
				dis[y] = dis[x] + ww;
				if (vis[y] != 1)
					qu.push((node) {
					dis[y], y
				});
			}
		}
	}
	return dis[end];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n + m; i++) {
		dis[i] = 0x3f3f3f3f;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a, t;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			add_edge(i, a, t);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dijistra(x, y) + w[x] + w[y] << endl;
		for (int i = 1; i <= n + m; i++) {
			dis[i] = 0x3f3f3f3f;
			vis[i] = 0;
		}
	}
	return 0;
}