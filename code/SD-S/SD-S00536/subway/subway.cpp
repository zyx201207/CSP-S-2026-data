// 60 pts.
// c \in [1, 15].
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXM = 20004, MAXN = 502;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct To {
	int to; ll wt;
	bool operator < (const To& o) const {
		return wt > o.wt;
	}
};

int c, n, m, d, q;
ll extra[MAXM];
vector< vector<ll> > dis;
vector<To> graph[MAXM + MAXN]; ll wwww;
priority_queue<To> pq;
queue<To> que;

void dijkstra(int st, vector<ll>& d) {
	d.assign(n + m + 1, INF);
	d[st] = 0LL;
	pq.push({st, 0LL});
	while (!pq.empty()) {
		int u = pq.top().to;
		ll ud = pq.top().wt;
		pq.pop();
		if (d[u] != ud) {continue;}
		for (To& e : graph[u]) {
			int v = e.to;
			ll vd = e.wt;
			if (d[v] > ud + vd) {
				d[v] = ud + vd;
				pq.push({v, d[v]});
			}
		}
	}
}

void bfs(int st, vector<ll>& d) {
	d.assign(n + m + 1, 0);
	que.push({st, 0});
	while (!que.empty()) {
		int u = que.front().to;
		ll ud = que.front().wt;
		que.pop();
		for (To& e : graph[u]) {
			int v = e.to;
			if (v != 1 && d[v] == 0) {
				d[v] = ud + 1;
				que.push({v, d[v]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> extra[i];
	}
	for (int i = 1, k, v, w; i <= n; i++) {
		cin >> k;
		while (k--) {
			cin >> v >> w; wwww = w;
			graph[m + i].push_back({v, (ll)w});
			graph[v].push_back({m + i, (ll)w});
		}
	}
	if (1 <= c && c <= 11) {
		dis.resize(m + 1);
		for (int i = 1; i <= m; i++) {
			dijkstra(i, dis[i]);
		}
		for (int i = 1, u, v; i <= q; i++) {
			cin >> u >> v;
			cout << dis[u][v] + extra[u] + extra[v] << "\n";
		}
		return 0;
	}
	if (12 <= c && c <= 15) {
		dis.resize(1);
		for (int i = 1, u, v; i <= q; i++) {
			cin >> u >> v;
			bfs(u, dis[0]);
			cout << dis[0][v] * wwww + extra[u] + extra[v] << "\n";
		}
		return 0;
	}
	return 0;
}
