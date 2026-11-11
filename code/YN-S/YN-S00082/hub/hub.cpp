#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, INF = 2e9;
int c, T;
int n, m;
vector<int> edge[N];
bool chs[N], vis[N];
int dis[N];
int ans;

void dfs1(int s) {
	vis[s] = 1;
	for (int nxt : edge[s])
		if (chs[nxt] && !vis[nxt])
			dfs1(nxt);
}

void dfs2(int s, int pre) {
	if (chs[s])
		dis[s] = 0;
	else
		dis[s] = INF;
	for (int nxt : edge[s]) {
		if (nxt != pre) {
			dfs2(nxt, s);
			dis[s] = min(dis[s], dis[nxt] + 1);
		}
	}
}

int dfs3(int s, int pre, int len) {
	int ret = min(len, dis[s]);
	for (int nxt : edge[s])
		if (nxt != pre)
			ret = max(ret, dfs3(nxt, s, min(len + 1, dis[s] + 1)));
	return ret;
}

void choose(int s, int tot) {
	if (s > n) {
		if (tot != m)
			return;
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (chs[i] && !vis[i]) {
				cnt++;
				dfs1(i);
			}
		}
		if (cnt > 2)
			return;
		dfs2(1, 0);
		ans = min(ans, dfs3(1, 0, INF));
		return;
	}
	if (tot < m) {
		chs[s] = 1;
		choose(s + 1, tot + 1);
		chs[s] = 0;
	}
	choose(s + 1, tot);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		edge[i].clear();
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	ans = INF;
	choose(1, 0);
	cout << ans << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}