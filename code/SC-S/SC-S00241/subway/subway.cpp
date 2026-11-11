#include <bits/stdc++.h>
#define ll long long
#define rep(a, b, c) for (int i = a; i <= b; i += c)
#define INF 0x3f3f3f3f
const int MAXN = 5e5 + 5;
using namespace std;
struct edge {
	int u, v, id, next;
} to[MAXN << 2];
int c, n, m, d, q, top, dis[MAXN], nodeid[MAXN], w[MAXN], head[MAXN << 2];
map<int, int> mp[MAXN];
void Insert(int u, int v, int id) {
	to[++top] = {u, v, id, head[u]};
	head[u] = top;
}
struct node {
	int pos, w, id;
	bool operator< (const node &other) const {
		return w > other.w;
	}
};
void Dijkstra(int start) {
	priority_queue<node> Q;
	for (int i = 1; i <= m; i++) {
		dis[i] = INF;
		nodeid[i] = 0;
	}
	dis[start] = w[start];
	Q.push({start, w[start], 0});
	while (!Q.empty()) {
		node now = Q.top();
		Q.pop();
		int u = now.pos, uid = now.id;
		if (now.pos > dis[u]) continue;
		nodeid[u] = uid;
		for (int i = head[u]; i; i = to[i].next) {
			int v = to[i].v, lineid = to[i].id;
			if (uid == lineid) {
				if (dis[v] > dis[u]) {
					dis[v] = dis[u];
					Q.push({v, dis[v], uid});
				}
			} else {
				int count = 0;
				if (uid == 0) count += mp[lineid][u];
				else count += mp[uid][u] + mp[lineid][u];
				if (dis[v] > dis[u] + count) {
					dis[v] = dis[u] + count;
					nodeid[v] = lineid;
					Q.push({v, dis[v], lineid});
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, t; i <= n; i++) {
		int all, a, a2;
		cin >> all >> a2 >> t;
		mp[i][1] = t;
		for (int j = 2; j <= all; j++) {
			cin >> a >> t;
			mp[i][a] = t;
			Insert(a, a2, i);
			Insert(a2, a, i);
			a2 = a;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		Dijkstra(x);
		cout << dis[y] + w[y] << '\n';
	}
	return 0;
}