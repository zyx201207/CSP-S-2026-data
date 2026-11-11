#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tp pair<ll, pair<int, int>>
using namespace std;
const int N = 500 + 5, M = 5e5 + 5;
int c, n, m, d, q;
int k[N];
int w[M];
pii a[N][N];
vector<pii> g[N];
vector<vector<ll>> ans;
int f (int ord, int u) {
	return (upper_bound(a[ord] + 1, a[ord] + 1 + k[ord], make_pair(u, 0)) - a[ord]);
}
vector<ll> dijkstra (int s) {
	vector<ll> dis(m + 5, 1e18);
	vector<int> outord(m + 5);
	bitset<M> vis;
	dis[s] = 0;
	priority_queue<tp, vector<tp>, greater<tp>> pq;
	pq.push(make_pair(0, make_pair(s, 0)));
	while (!pq.empty()) {
		int u, uord;
		tie(u, uord) = pq.top().second;
		pq.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		for (pii i : g[u]) {
			int v = i.first, vord = i.second;
			if (uord == vord) {
				if (dis[v] > dis[u]) {
					dis[v] = dis[u];
					outord[v] = vord;
					pq.push(make_pair(dis[v], make_pair(v, vord)));
				}
			}
			else if (!uord) {
				if (dis[v] > dis[u] + a[vord][f(vord, u)].second) {
					dis[v] = dis[u] + a[vord][f(vord, u)].second;
					outord[v] = vord;
					pq.push(make_pair(dis[v], make_pair(v, vord)));
				}
			}
			else {
				if (dis[v] > dis[u] + a[uord][f(uord, u)].second + a[vord][f(vord, u)].second) {
					dis[v] = dis[u] + a[uord][f(uord, u)].second + a[vord][f(vord, u)].second;
					outord[v] = vord;
					pq.push(make_pair(dis[v], make_pair(v, vord)));
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
//		cerr << dis[i] << ' ' << a[outord[i]][f(outord[i], i)].second << '\n';
		dis[i] += a[outord[i]][f(outord[i], i)].second;
	}
	return dis;
}
int main () {
//	cerr << log(M) << '\n';
//	cerr << (2e4) * (2e4) * log(2e4) << '\n';
//	return 0;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	ans.resize(m + 5);
//	memset(a, 0x3f, sizeof a);
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j].first >> a[i][j].second;
//			cerr << a[i][j] << ' ' << t[i][j] << ' ';
		}
		sort(a[i] + 1, a[i] + 1 + k[i]);
		for (int j = 1; j <= k[i]; ++j) {
			if (j > 1) {
				g[a[i][j].first].emplace_back(a[i][j - 1].first, i);
				g[a[i][j - 1].first].emplace_back(a[i][j].first, i);
			}
		}
//		cerr << '\n';
	}
	for (int i = 1; i <= m; ++i) {
		for (pii j : g[i]) {
			cerr << j.first << ',' << j.second << ' ';
		}
		cerr << '\n';
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (ans[x].empty() && ans[y].empty()) {
			ans[x] = dijkstra(x);
		}
		if (!ans[x].empty()) {
			cout << ans[x][y] + w[x] + w[y] << '\n';
//			for (int i = 1; i <= m; ++i) {
//				cerr << ans[x][i] << " \n"[i == m];
//			}
		}
		else {
			cout << ans[y][x] + w[x] + w[y] << '\n';
//			for (int i = 1; i <= m; ++i) {
//				cerr << ans[y][i] << " \n"[i == m];
//			}
		}
	}
	return 0;
}