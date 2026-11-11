#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 20, K = 4e4 + 20, M = 1e6 + 20;
const ll inf = 1e18;
int c, n, m, d, q;
// 编号，线路，站，最大线，测试 
ll w[K];
struct edge {
	ll v, w, nxt;
} e[M];
int head[K * 2], cnt;
void add (int u, int v, int w) {
	e[++ cnt] = {v, w, head[u]};
	head[u] = cnt;
}
ll dis[N][N];
struct node {
	ll l, u;
	bool operator < (const node b) const {
		return l > b.l;
	} 
};
void dij1 (int s) {
	memset (dis[s], 0x3f3f3f3f, sizeof (dis[s]));
	priority_queue <node> pq;
	dis[s][s] = 0;
	pq.push ({0, s});
	while (pq.size ()) {
		node f = pq.top ();
		pq.pop ();
		int u = f.u, l = f.l;
		if (l > dis[s][u])
			continue;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if (dis[s][u] + w < dis[s][v]) {
				dis[s][v] = dis[s][u] + w;
				pq.push ({dis[s][v], v});
			}
		}
	} 
}
void work1 () {
	for (int i = 1; i <= m; i ++)
			dij1 (i);
	for (int i = 1; i <= q; i ++) {
		int s, t;
		cin >> s >> t;
		cout << dis[s][t] + w[s] + w[t] << '\n';
	}
}
int diss[K];
void dij2 (int s) {
	memset (diss, 0x3f3f3f3f, sizeof (diss));
	priority_queue <node> pq;
	diss[s] = 0;
	pq.push ({0, s});
	while (pq.size ()) {
		node f = pq.top ();
		pq.pop ();
		int u = f.u, l = f.l;
//		cout << "Test " << u << " " << l << " " << diss[u] << '\n';
		if (l > diss[u])
			continue;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v, w = e[i].w;
//			cout << "CCF " << w << " " << v << " " << diss[v] << '\n';
			if (diss[u] + w < diss[v]) {
//				cout << "QwQ";
				diss[v] = diss[u] + w;
				pq.push ({diss[v], v});
			}
		}
	} 
}
void work2 () {
	for (int i = 1; i <= q; i ++) {
		int s, t;
		cin >> s >> t;
		dij2 (s);
		cout << diss[t] + w[t] + w[s] << '\n';
	}
}
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	// 1 - m 站厅 
	// m + 1 - m + n + 1 线路 
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			add (m + i, a, t), add (a, m + i, t);
		}
	}
	if (12 <= c && c <= 15) {
		work2 ();
	}
	else {
		work1 (); 
	}
	return 0;
}
// 1 ~ 15 60 pts
