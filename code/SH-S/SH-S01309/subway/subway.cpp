#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXM 500005
typedef pair<ll, int> pli;

const ll INF = 1e17;
int c, n, m, d, q, cnt;
int head[MAXM], nxt[MAXM], to[MAXM];
ll w[MAXM], val[MAXM], dis[MAXM], dis_[2000][2000];
void addedge (int u, int v, ll vl) {
	val[++cnt] = vl;
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
ll zdl (int x, int y) {
	for (int i=1; i<=m+n; i++) dis[i] = INF;
	priority_queue <pli, vector<pli>, greater<pli> > pq;
	dis[x] = 0;
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		ll dst = pq.top().first;
		int x = pq.top().second;
		if (x == y) return dst;
		pq.pop();
		for (int e=head[x]; e; e=nxt[e]) {
			int v = to[e];
			if (dis[x] + val[e] < dis[v]) {
				dis[v] = dis[x] + val[e];
				pq.push(make_pair(dis[v], v));
			}
		}
	}
	return INF;
}
void zdl_ (int n) {
	for (int i=1; i<=m+n; i++) dis_[n][i] = INF;
	priority_queue <pli, vector<pli>, greater<pli> > pq;
	dis_[n][n] = 0;
	pq.push(make_pair(0, n));
	while (!pq.empty()) {
		ll dst = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		for (int e=head[x]; e; e=nxt[e]) {
			int v = to[e];
			if (dis_[n][x] + val[e] < dis_[n][v]) {
				dis_[n][v] = dis_[n][x] + val[e];
				if (v < n) dis_[v][n] = dis_[n][v];
				pq.push(make_pair(dis_[n][v], v));
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) cin >> w[i];
	for (int i=1, k, a; i<=n; i++) {
		cin >> k;
		for (int j=1; j<=k; j++) {
			ll t;
			cin >> a >> t;
			addedge(m+i, a, t);
			addedge(a, m+i, t);
		}
	}
	if (c <= 11) {
		for (int i=1; i<=m; i++) zdl_(i);
		int x, y;
		while (q--) {
			cin >> x >> y;
			cout << dis_[x][y] + w[x] + w[y] << '\n';
		}
		return 0;
	} 
	for (int i=1, x, y; i<=q; i++) {
		cin >> x >> y;
		ll ans = zdl(x, y) + w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}

