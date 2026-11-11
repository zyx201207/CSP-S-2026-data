#include <bits/stdc++.h>
#define pr pair<int,int>
using namespace std;
long long c, n, m, d, q, w[500005], cnt, first[500005], k[505], t[50005][505], a[50005][505], u, v, vis[500005],
     dis[500005];

struct node {
	int to, nxt, w;
} edge[1000005];

inline void add(int u1, int v1, int ww) {
	cnt++;
	edge[cnt].to = v1;
	edge[cnt].w = ww;
	edge[cnt].nxt = first[u1];
	first[u1] = cnt;
}

inline void spfa(int x) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	priority_queue<pr, vector<pr>, greater<pr> > q;
	dis[x] = 0;
	vis[x] = 1;
	q.push({dis[x], x});
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		for (int i = first[u]; i; i = edge[i].nxt) {
			int v = edge[i].to, w = edge[i].w;
			if (dis[v] >= dis[u] + w and vis[v] != 1) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
				vis[v] = 1;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			add(a[i][j - 1], a[i][j], 11);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int l = 1; l <= k[j]; l++) {
				for (int o = 1; o <= k[i]; o++) {
					if (a[i][o] == a[j][l]) {
						dis[a[i][o]] = 0, dis[a[j][l]] = 0;
						add(a[i][o], a[j][l], t[i][o] + t[j][l]);
						add(a[j][l], a[i][o], t[i][o] + t[j][l]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> u >> v;
		spfa(u);
		cout << dis[v] + w[v] + w[u] << "\n";
	}
	return 0;
}
