#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= (r); ++i)
#define req(i, l, r) for (int i = l; i < (r); ++i)
#define per(i, r, l) for (int i = r; i >= (l); --i)
#define qer(i, r, l) for (int i = r; i > (l); --i)
#define eb emplace_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const int MAXN = 502, N = 2.5e5 + 1002, M = 5e5 + 2002;
const ll INF = 1e18;
struct edge {
	int v, nxt;
	ll t;
} e[M];
int cid, n, m, D, q, k[MAXN], cnt[M], h[M], tot, idx, id[MAXN][N];
vector<int> a[MAXN];
vector<pii> vec[M];
vector<ll> t[MAXN];
ll w[M], d[MAXN][N];
bool vis[M];
void add(int u, int v, const ll t) {
	e[++idx] = {v, h[u], t};
	h[u] = idx;
	// e[++idx] = {v, h[v], t};
	// h[v] = idx;
}
priority_queue<pli, vector<pli>, greater<pli>> pq;
void dijkstra(int x) {
	rep(i, 1, tot) d[x][i] = INF;
	rep(i, 1, tot) vis[i] = 0;
	pq.emplace(0ll, id[x][a[x][1]]);
	vis[id[x][a[x][1]]] = 0;
	d[x][id[x][a[x][1]]] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = h[u], v; i; i = e[i].nxt) {
			v = e[i].v;
			if (d[x][v] > d[x][u] + e[i].t) {
				d[x][v] = d[x][u] + e[i].t;
				pq.emplace(d[x][v], v);
			}
		}
	}
	// rep(i, 1, tot) cout << d[x][i] << ' ';
	// cout << '\n';
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> cid >> m >> n >> D >> q; // swap the n and m
	rep(i, 1, n) cin >> w[i];
	rep(i, 1, m) {
		cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		rep(j, 1, k[i]) cin >> a[i][j] >> t[i][j];
		rep(j, 1, k[i]) ++cnt[a[i][j]], vec[a[i][j]].eb(i, j);
	}
	rep(i, 1, m) {
		id[i][a[i][1]] = ++tot;
		rep(j, 2, k[i]) {
			if (cnt[a[i][j]] != 1 || cnt[a[i][j - 1]] != 1)
				id[i][a[i][j]] = ++tot;
			else id[i][a[i][j]] = id[i][a[i][j - 1]];
			if (id[i][a[i][j]] != id[i][a[i][j - 1]]) {
				ll sum = 0;
				add(id[i][a[i][j - 1]], id[i][a[i][j]], 0);
				add(id[i][a[i][j]], id[i][a[i][j - 1]], 0);
			}
		}
	}
	rep(i, 1, n) for(auto x : vec[i]) for(auto y : vec[i]) {
		add(id[x.first][i], id[y.first][i], t[x.first][x.second] + t[y.first][y.second]);
		add(id[y.first][i], id[x.first][i], t[x.first][x.second] + t[y.first][y.second]);
	}
	// rep(i, 1, n) for (int i = h[i]; i; i = e[i].nxt)
	// 	cout << i << ' ' << e[i].v << '\n';
	// rep(i, 1, n) cout << id[i] << ' '; cout << '\n';
	rep(i, 1, m) dijkstra(i);
	// cout << d[1][id[3][3]] << '\n';
	int x, y;
	ll ans;
	while (q--) {
		cin >> x >> y;
		ans = INF;
		for (auto a : vec[x]) for (auto b : vec[y]) {
			ll sum = w[x] + w[y] + d[a.first][id[b.first][y]] + t[a.first][a.second] + t[b.first][b.second];
			// if (a.second == 1) sum -= t[a.first][a.second];
			ans = min(ans, sum);
		}
		// cout << ans - w[x] - w[y] << ' ';
		cout << ans << '\n';
	}
	return 0;
}
/*
ulimit -s 1024000000
g++ -o subway subway.cpp -std=c++14 -O2 -static
./subway
*/