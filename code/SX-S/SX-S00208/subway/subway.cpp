#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+5, N = 1e5+5;
int c, n, m, d, q;
vector<pair<int, int>>v[M * 22];
int ans[N], dis[M];
int zt = 0;
vector<pair<int, int>>r[M];
bool bl[M], vis[M];
queue<int>que;

void dij(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0, vis[s] = 1;
	priority_queue<pair<int, int>>qq;
	qq.push({0, s});
	while (!qq.empty()) {
		int u = qq.top().second;
		qq.pop();
		vis[u] = 1;
		for (auto it : v[u]) {
			int to = it.first, w = it.second;
			if (dis[u] + w < dis[to]) {
				dis[to] = dis[u] + w;
				qq.push({-dis[to], to});
			}
		}
	}
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		int w;
		scanf("%d", &w);
		v[i].push_back({m + i, w});
		v[m + i].push_back({i, w});
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		int u = 0;
//		cout << 1 << endl;
		for (int j = 1; j <= k; j++) {
			int a, t;
			scanf("%d %d", &a, &t);
			zt++;
			v[m + a].push_back({2 * m + zt, t});
			v[2 * m + zt].push_back({m + a, t});
			if (j != 1) {
				v[2 * m + u].push_back({2 * m + zt, 0});
				v[2 * m + zt].push_back({2 * m + u, 0});
			}
			u = zt;
		}
	}

//	cout << "！！！！！！！！！！！！！！！！！！！！！！\n";
//	for (int i = 1; i <= 22 * m; i++) {
//		for (auto it : v[i]) {
//			printf("貫%d欺%d,幡峙%d\n", i, it.first, it.second);
//		}
//	}
//	cout << "！！！！！！！！！！！！！！！！！！！！！！\n";

	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		r[x].push_back({y, i});
		if (!bl[x]) {
			que.push(x);
			bl[x] = 1;
		}
	}
	while (!que.empty()) {
		int op = que.front();
		que.pop();
		dij(op);
		for (auto it : r[op]) {
			ans[it.second] = dis[it.first];
		}
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
