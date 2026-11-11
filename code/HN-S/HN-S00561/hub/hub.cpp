#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

int t, c;
int n, m;
vector<int> e[N]; 
int b[N], l, juli[N];
bool vis[N];

void dfs1(int x, int fa, int sum) {
	juli[x] = min(juli[x], sum);
	int len = e[x].size();
	for (int i = 0; i < len; i++) {
		int y = e[x][i];
		if (y == fa) continue;
		dfs1(y, x, sum + 1);
	}
}

int col[N], color;

void dfs2(int x, int fa) {
	col[x] = color;
	int len = e[x].size();
	for (int i = 0; i < len; i++) {
		if (e[x][i] == fa || !vis[e[x][i]]) continue;
		dfs2(e[x][i], x);
	}
}

bool liantong() {
	for (int i = 1; i <= n; i++) {
		if (vis[i] && !col[i]) {
			color++;
			dfs2(i, 0);
		}
	}
	return color <= 2;
}

int check() {
	int ans2 = 0;
	color = 0;
	for (int i = 1; i <= n; i++) col[i] = vis[i] = 0;
	for (int i = 1; i <= l; i++) vis[b[i]] = 1;
	if (!liantong()) return 1e18;
	for (int i = 1; i <= n; i++) juli[i] = 1e18;
	for (int i = 1; i <= l; i++) dfs1(b[i], 0, 0);
	for (int i = 1; i <= n; i++) {
		ans2 = max(ans2, juli[i]);
	}
	return ans2;
}

int ans = 1e18, cnt;

void dfs(int x) {
	if (cnt > m) return ;
	if (x > n) {
		if (cnt < m) return ;
		ans = min(ans, check());
		return ;
	}
	cnt++;
	b[++l] = x;
	dfs(x + 1);
	b[l--] = 0;
	cnt--;
	dfs(x + 1);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) e[i].clear(), juli[i] = 1e18;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = 1e18;
	dfs(1);
	cout << ans << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
tui yi le.
*/
