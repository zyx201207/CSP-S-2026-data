#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll inf = 1e18;

//int cnt = 0;
vector<vector<pair<int,ll> > > g;

vector<ll> dij(int n, int s) {
	vector<ll> dis(n + 1, inf);
	vector<bool> poped(n + 1);
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
	pq.push({0, s});
	dis[s] = 0;
	while (!pq.empty()) {
		ll u = pq.top().second;
		pq.pop();
		if (poped[u]) continue;
		poped[u] = true;
		for (auto &[v, w] : g[u]) {
//			cnt++;
			if (dis[v] > dis[u] + w && !poped[v]) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	return dis;
}

void solve() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	g.resize(m + n + 5);
	vector<ll> w2(m + 1);
	for (int i = 1; i <= m; ++i) cin >> w2[i];
	for (int u = 1; u <= n; ++u) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int v;
			cin >> v;
			v += n;
			ll w;
			cin >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	vector<vector<ll> > dis(n + 1);
	for (int i = 1; i <= n; ++i) {
//		cnt = 0;
		dis[i] = dij(n + m, i);
//		cout << cnt << '\n';
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		ll ans = inf;
		for (auto &[v, w] : g[s + n]) {
//			cnt++;
//			cout << v << ' ' << w << '\n';
			ans = min(ans, dis[v][t + n] + w);
		}
		ans += w2[s] + w2[t];
//		cout << cnt << '\n';
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	solve();
	return 0;
}
// 正解！！！！！！！！
// n (m + n) log (m + n) + q d！！！！
// 完！全！可！过！
// CODE BY AYACHINENE