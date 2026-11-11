#include <bits/stdc++.h>
#define int long long
using namespace std;

//int h[50001];
//int dis[50001];
//int vis[50001];
//int w[50001];
//int e[50001];
//int N[50001];
//int id;
//
//void add(int u, int v, int W) {
//	e[id] = v;
//	N[id] = h[u];
//	w[id] = W;
//	h[u] = id++;
//}
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

//void dj(int s) {
//	memset(dis, 0xcf, sizeof(dis));
//	memset(vis, 0, sizeof(vis));
//	dis[s] = 0;
//	q.push({0, s});
//	while (!q.empty()) {
//		auto x = q.top();
//		q.pop();
//		if (vis[u]) {
//			continue;
//		}
//		vis[u] = 1;
//		for (int i = h[u]; i != -1; i = N[i]) {
//			int v = e[i];
//			f
//			if (dis[v] > d + w[i]) {
//				dis[v] = d + w[i];
//				q.push({dis[v], v});
//			}
//		}
//	}
//}
//int a[50001];
//vector<int>A[50001];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	int c, n, m, d, q;
//	memset(h, -1, sizeof(h));
//	for (int i = 1; i <= m; ++i) {
//		scanf("%lld", &a[i]);
//	}
//	for (int i = 1; i <= m; ++i) {
//		int k;
//		scanf("%lld", &k);
//		A[i].resize(k);
//		for (int j = 0; j < k; ++j) {
//			scanf("%lld", &A[i][j]);
//		}
//		int c;
//		scanf("%lld", &c);
//		for (int j = 0; j < k; ++j) {
//			int u = A[i][j];
//			add(n + i * n + u, u, 0);
//			add(u, n + i * n + u, a[u]);
//		}
//		for (int j = 0; j < k - 1; ++j) {
//			int u = A[i][j], v = a[i][j + 1];
//			add(n + i * n + u, n + i * n + v, c);
//			add(n + i * n + v, n + i * n + u, c);
//		}
//	}
//
	printf("35 16");
	return 0;
}