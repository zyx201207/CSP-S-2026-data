#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 507, M = 5e5 + 7;

int c, n, m, d, q;
ll ans;
unordered_map<int, int> t[N];
int w[M];
struct node {
	int v, id;
};
vector<node> e[M];
vector<node> g[M];

inline
void dfs(int u, int ed, int id, ll dis) {
	if (ans <= dis) return ;
	if (u == ed) {
		int w = 0;
		if (t[id].count(u)) w = t[id][u];
		ans = min(ans, dis + w); 
		return ;
	}
	for (auto now : e[u]) {
		int v = now.v;
		if (id != now.id) {
			int w = 0;
			if (t[id].count(u)) w += t[id][u];
			if (t[now.id].count(u)) w += t[now.id][u];
			dfs(v, ed, now.id, dis + w);
		} else {
			dfs(v, ed, now.id, dis);
		}
	}
}

inline
void dfs1(int u, int ed, int id, ll dis) {
	if (ans <= dis) return ;
	if (u == ed) {
		int w = 0;
		if (t[id].count(u)) w = t[id][u];
		ans = min(ans, dis + w); 
		return ;
	}
	for (auto now : g[u]) {
		int v = now.v;
		if (id != now.id) {
			int w = 0;
			if (t[id].count(u)) w += t[id][u];
			if (t[now.id].count(u)) w += t[now.id][u];
			dfs1(v, ed, now.id, dis + w);
		} else {
			dfs1(v, ed, now.id, dis);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int u = 0, v = 0;
		for (int j = 1; j <= k; j++) {
			cin >> v;
			cin >> t[i][v];
			if (j != 1) e[u].push_back({v, i}), g[v].push_back({u, i});
			u = v;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ans = 2e18;
		dfs(x, y, 0, w[x] + w[y]);
		dfs1(x, y, 0, w[x] + w[y]);
		cout << ans << '\n';
	}
	return 0;
}
