#include <bits/stdc++.h>
#define ll int
using namespace std;
ll C, T, n, K, ans, chs[1001000], vis[1001000], dep[1001000], cnt, X;
vector<ll> G[1001000];
queue<ll> q;
void dfs(ll lx) {
	q.push(lx);
	while (!q.empty()) {
		X = q.front(); q.pop();
		vis[X] = 1;
		for (auto Y : G[X]) if (chs[Y] && ! vis[Y]) vis[Y] = 1, q.push(Y);
	}
}
void bfs() {
	for (int i = 1; i <= n; i ++) if (chs[i]) dep[i] = 0, q.push(i);
	while (!q.empty()) {
		ll X = q.front(); q.pop();
		for (auto Y : G[X]) if (dep[Y] == -1) dep[Y] = dep[X] + 1, q.push(Y);
	}
	ll res = 0;
	for (int i = 1; i <= n; i ++) res = max(res, dep[i]);
	ans = min(ans, res);
}
void solve() {
	cin >> n >> K;
	for (int i = 1, u, v; i < n; i ++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
	ans = n + 1;
	for (int S = 0, i; S < (1 << n); S ++) {
		if (__builtin_popcount(S) != K) continue;
		for (i = 1; i <= n; i ++) chs[i] = ((S >> (i - 1)) & 1), vis[i] = 0;
		cnt = 0;
		for (i = 1; i <= n; i ++) if (chs[i] && ! vis[i]) cnt ++, dfs(i);
		if (cnt > 2) continue;
		for (i = 1; i <= n; i ++) dep[i] = -1;
		bfs();
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i ++) G[i].clear();
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> T;
	while (T --) solve();
	return 0;
}
