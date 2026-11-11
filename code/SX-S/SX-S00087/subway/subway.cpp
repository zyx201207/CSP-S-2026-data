#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+507;
#define int long long

struct edge {
	int to, w, nxt;
} e[N];
int c, n, m, d, q, z[N], hd[N], cnt, u, v, w, k;
int dis[N], vis[N];

inline void add(int u, int v, int w) {
	e[++cnt] = {v, w, hd[u]};
	hd[u] = cnt;
}

inline bool cmp(edge x, edge y) {
	return x.w < y.w;
}

inline void spfa(int s, int f) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int>> q;
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		//	int d = q.front().first;
		int u = q.front().second;
		vis[u] = 1;
		q.pop();
		for (int i = hd[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			int w = e[i].w;
			if (u == v)
				continue;
			/*if (vis[v] == 1)
				continue;*/
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
				vis[v] = 1;
			}
		}
	}
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> z[i];
	int p = m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		p++;
		for (int j = 1; j <= k; j++) {
			cin >> v >> w;
			add(p, v, w);
			add(v, p, w);
		}
	}

//	sort(e + 1, e + n *k * 2 + 1, cmp);
	while (q--) {
		int x, y;
		cin >> x >> y;
		spfa(x, y);
		/*	for (int i = 1; i <= m; i++)
				cout << dis[i] << " ";*/
		cout << dis[y] + z[x] + z[y]  << '\n';
	}
	return 0;
}