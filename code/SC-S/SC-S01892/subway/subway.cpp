#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define file "subway"
#define int long long
using namespace std;
int c, n, m, D, q;
struct Edge {
    int v, w, nxt;
}edge[5000000 + 5];
int head[1000000 + 5], idx;
void add(int u, int v, int w) {
//	cerr << u << ' ' << v << ' ' << w << endl;
    edge[++idx] = { v, w, head[u] };
    head[u] = idx;
}
int dis[1000000 + 5]; bool vis[1000000 + 5];
int dist[1000 + 5][1000 + 5];
using pq = __gnu_pbds::priority_queue<
	pair<int, int>, greater<pair<int, int>>,
	__gnu_pbds::pairing_heap_tag>;
pq::point_iterator pnt[1000000 + 5];
void dij(int s) {
    pq q;
	for (int i = 1; i <= n + m; ++i)
		dis[i] = 0x3f3f3f3f3f3f3f3f,
		vis[i] = 0, pnt[i] = nullptr;
	dis[s] = 0; pnt[s] = q.push(make_pair(0, s));
	while (!q.empty()) {
		int now = q.top().second; q.pop();
		if (vis[now]) continue; vis[now] = 1;
		for (int i = head[now]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = dis[now] + edge[i].w;
			if (c == 22 || c == 23) {
				for (int j = head[v]; j; j = edge[j].nxt) {
					if (edge[j].v == now) continue;
					v = edge[j].v; w += edge[j].w;
					break;
				}
			}
			if (dis[v] > w) {
				dis[v] = w;
				if (pnt[v] != nullptr) q.modify(pnt[v], make_pair(w, v));
				else pnt[v] = q.push(make_pair(w, v));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		dist[s][i] = dis[i];
}
void bfs(int s) {
	queue<int>q;
	for (int i = 1; i <= n + m; ++i)
		vis[i] = 0;
	dis[s] = 0; q.push(s); vis[s] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = edge[i].nxt) {
			int v = edge[i].v, w = dis[now] + edge[i].w;
			if (!vis[v]) {
				dis[v] = w; q.push(v); vis[v] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		dist[s][i] = dis[i];
}
int w[1000000 + 5];
int32_t main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int j = 1; j <= n; ++j) {
		int k; cin >> k;
		for (int i = 1; i <= k; ++i) {
			int a, t; cin >> a >> t;
			add(j, n + a, t);
			add(n + a, j, t);
		}
	}
	if (16 <= c && c <= 19)
		for (int i = 1; i <= n; ++i) bfs(i);
	else for (int i = 1; i <= n; ++i) dij(i);
	for (int i = 1, x, y; i <= q; ++i) {
		cin >> x >> y; int ans = LLONG_MAX;
		for (int i = head[x + n]; i; i = edge[i].nxt)
			for (int j = head[y + n]; j; j = edge[j].nxt)
				ans = min(ans, edge[i].w + edge[j].w + dist[edge[i].v][edge[j].v]);
		cout << ans + w[x] + w[y] << endl;
	}
    return 0;
}
/*
我已严肃坠机，怎么 -S T2 都做不出来了
如此状态，何以 NOIP？
100+84+24+12
！？区区？！
算了，今年随便考了，反正都考不好
*/