#include <bits/stdc++.h>
using namespace std;
const int maxm = 500005, maxn = 505, inf = 0x3f3f3f3f;
int w[maxm], dis[maxm*2], vis[maxm*2];
struct node {
	int v, t;
};
vector<node> G[maxm*2];
void insert(int u, int v, int t) {
	G[u].push_back(node{v, t});
	G[v].push_back(node{u, t});
}
int spfa(int st, int ed) {
	queue<int> q;
	memset(dis, inf, sizeof(dis));
	dis[st] = 0;
	q.push(st);
	vis[st] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v, t = G[u][i].t;
			if (dis[v] > dis[u] + t) {
				dis[v] = dis[u] + t;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return dis[ed];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int cnt = m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			insert(a, ++cnt, t);
			if (j >= 2) insert(cnt, cnt-1, 0);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << spfa(x, y) + w[x] + w[y] << endl;
	}
	return 0;
}
