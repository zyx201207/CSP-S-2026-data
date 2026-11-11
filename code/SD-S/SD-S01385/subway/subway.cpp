#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long ll;
typedef pair<ll, int> pii;
int c, n, m, d, q, x, y, a[N], vis[N];
int head[N], nxt[N], to[N], val[N], idx;
ll dis[N], _dis[1005][1005];
void add (int u, int v, int w) {
	to[++idx] = v, val[idx] = w;
	nxt[idx] = head[u], head[u] = idx;
}
void dij (int s) {
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	for (int i = 1; i <= n + m; ++i)
		dis[i] = 1e18, vis[i] = 0;
	dis[s] = 0, Q.emplace(0, s);
	while (Q.size()) {
		int u = Q.top().second;
		Q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i], w = val[i];
			if (dis[v] > dis[u] + w)
				dis[v] = dis[u] + w, Q.emplace(dis[v], v);
		}
	}
}
void solve () {
	queue<int> Q;
	for (int i = 1; i <= n + m; ++i)
		dis[i] = 1e18, vis[i] = 0;
	dis[x] = 0, vis[x] = 1, Q.push(x);
	while (Q.size()) {
		int u = Q.front();
		Q.pop();
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (!vis[v])
				dis[v] = dis[u] + 1, vis[v] = 1, Q.push(v);
		}
	}
	cout << dis[y] * val[1] + a[x] + a[y] << endl;
}
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1, k; i <= m; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j)
			cin >> x >> y, add(x, i + n, y), add(i + n, x, y);
	}
	if (c >= 12 && c <= 15) {
		while (q--)
			cin >> x >> y, solve();
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		dij(i);
		for (int j = 1; j <= n; ++j)
			_dis[i][j] = dis[j];
	}
	while (q--)
		cin >> x >> y, cout << a[x] + a[y] + _dis[x][y] << endl;
	return 0;
}
