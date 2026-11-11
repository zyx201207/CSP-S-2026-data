#include <bits/stdc++.h>
#define int long long
#define P pair<int, int>
#define fi first
#define se second
using namespace std;
const int M = 5e5 + 5;
const int D = 25;
const int INF = 2e18;
int c, n, m, d, q;
int ans;
int w[M];
int cnt[M];
int dis[M];
struct node {
	int id, a, t;
};
vector<node> g[M];
struct node1 {
	int id, t;
} ti[M][D];
struct node2 {
	int id, u, w, t;
	bool operator < (const node2& other) const {
		return w > other.w;
	}
};
void init() {
	for (int i = 1; i <= m; i++) {
		dis[i] = INF;
	}
	ans = INF;
}
void dijkstra(int start, int end) {
	init();
	priority_queue<node2> q;
	q.push({0, start, w[start], 0});
	dis[start] = w[start];
	while (!q.empty()) {
		node2 now = q.top(); q.pop();
		int u = now.u, id = now.id;
		if (u == end) {
			int t;
			for (int i = 1; i <= d; i++) {
				if (ti[u][i].id == id) {
					t = ti[u][i].t;
					break;
				}
			}
			ans = min(ans, now.w + now.t + t + w[end]);
			continue;
		}
		for (auto it : g[u]) {
			int v = it.a, w = it.t;
			if (it.id == id) {
				if (now.w < dis[v]) {
					int t = 0;
					for (int i = 1; i <= cnt[v]; i++) {
						if (ti[v][i].id == id) {
							t = ti[v][i].t;
							break;
						}
					}
					dis[v] = now.w + now.t + t;
					q.push({id, v, now.w, now.t});
				}
			} else {
				int t = 0;
				for (int i = 1; i <= cnt[u]; i++) {
					if (ti[u][i].id == it.id) {
						t = ti[u][i].t;
						break;
					}
				}
				int t1 = 0;
				for (int i = 1; i <= cnt[u]; i++) {
					if (ti[u][i].id == id) {
						t1 = ti[u][i].t;
						break;
					}
				}
				if (now.w + now.t + t1 < dis[v]) {
					dis[v] = now.w + now.t + t1 + t;
					q.push({it.id, v, now.w + now.t + t1, t});
				}
			}
		}
	}
}
void solve() {
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k, a_lst, t_lst;
		scanf("%lld%lld%lld", &k, &a_lst, &t_lst);
		ti[a_lst][++cnt[a_lst]] = {i, t_lst};
		for (int j = 2; j <= k; j++) {
			int a, t;
			scanf("%lld%lld", &a, &t);
			g[a_lst].push_back({i, a, t});
			ti[a][++cnt[a]] = {i, t};
			a_lst = a, t_lst = t;
		}
	}
	while (q--) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		if (x > y) swap(x, y);
		dijkstra(x, y);
		printf("%lld\n", ans);
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	solve();
	return 0;
}