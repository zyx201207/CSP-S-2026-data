#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int N = 5e5+5, M = 1e7+5;
ll c, n, m, d, T, cnt = 1, a[N],  head[M], dist[N], ans[N];
bool vis[N];
priority_queue<pll, vector<pll>, greater<pll> > q;

struct Line {
	ll a, t;
} line[N];

struct edge {
	ll ed, nxt, val;
} e[M << 1];

struct Query {
	ll bg, ed, id;
} Q[N];

bool cmp(Query x, Query y) {
	if (x.bg == y.bg)
		return x.ed < y.ed;
	return x.bg < y.bg;
}

void add(ll bg, ll ed, ll val) {
	e[cnt].ed = ed;
	e[cnt].val = val;
	e[cnt].nxt = head[bg];
	head[bg] = cnt++;
}

void dijkstra(ll bg) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	q.push(make_pair(0, bg));
	dist[bg] = 0;
	while (!q.empty()) {
		ll u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nxt) {
			ll v = e[i].ed, w = e[i].val;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push(make_pair(dist[v], v));
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> line[j].a >> line[j].t;
		for (int j = 1; j <= k; j++) {
			for (int z = j + 1; z <= k; z++) {
				add(line[j].a, line[z].a, line[j].t + line[z].t);
				add(line[z].a, line[j].a, line[j].t + line[z].t);
			}
		}
	}
	for (int i = 1; i <= T; i++) {
		cin >> Q[i].bg >> Q[i].ed;
		Q[i].id = i;
	}
	sort(Q + 1, Q + T + 1, cmp);
	for (int i = 1; i <= T; i++) {
		if (Q[i].bg != Q[i - 1].bg)
			dijkstra(Q[i].bg);
		ans[Q[i].id] = dist[Q[i].ed] + a[Q[i].bg] + a[Q[i].ed];
	}
	for (int i = 1; i <= T; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}