#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll inf = 1e18;

int bfs(int s, vector<vector<int> > &g, int n) {
	vector<int> dis(n + 1);
	queue<int> q1;
	q1.push(s);
	while (!q1.empty()) {
		int u = q1.front();
		q1.pop();
		for (int v : g[u]) {
			if (!dis[v]) {
				dis[v] = dis[u] + 1;
				q1.push(v);
			}
		}
	}
	int cnt = 0;
	queue<int> q2;
	vector<int> vis(n + 1);
	vis[s] = 1;
	q2.push(s);
	while (!q2.empty()) {
		int u = q2.front();
		q2.pop();
		for (int v : g[u]) {
			if (dis[v] != dis[u] + 1) continue;
			vis[v] += vis[u];
			q2.push(v);
		}
	}
	for (int i = s; i <= n; ++i) {
		
		if (vis[i] == 2) {
			cnt++;
//			cout << vis[i] << ' ' << dis[i] << '\n';
//			cout << s << ' ' << i << '\n';
		}
		
	}
	return cnt;
}

int case2(ll d, int n, vector<ll> x) {
	ll de = x[2] - x[1];
	if (d >= de * 2) {
		return min(0, n - 3);
	}
	return 0;
}
void solve(int c) {
	vector<ll> x;
	ll d;
	int n;
	cin >> n >> d;
	x.resize(n + 1);
	vector<vector<int> > g(n + 1);
	for (int i = 1; i <= n; ++i) cin >> x[i];
	if (c == 11 || c == 12) {
		cout << case2(d, n, x) << '\n';
		return;
	}
	for (int u = 1; u <= n; ++u) {
		for (int v = u + 1; v <= n; ++v) {
			if (x[v] - x[u] > d) break;
//			cout << u << ' ' << v << '\n';
			g[u].push_back(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += bfs(i, g, n);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) solve(c);
	return 0;
}
// CODE BY AYACHINENE