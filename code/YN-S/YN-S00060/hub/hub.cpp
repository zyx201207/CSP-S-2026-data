#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int c, T, n, k;
vector<int> node[N];
int dist[N][N];
bool p[N];
int cc[N];
bool dd[20];
int ans;

void dfs(int id, int u) {
	for (auto i : node[id]) {
		if (p[i])
			continue;
		p[i] = 1;
		dist[u][i] = dist[u][id] + 1;
		dfs(i, u);
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			p[j] = 0;
		dist[i][i] = 0;
		p[i] = 1;
		dfs(i, i);
	}
	for (int j = 1; j <= n; j++)
		p[j] = 0;
	ans = (1 << 30);
}

void dfs1(int id) {
	for (auto i : node[id]) {
		if (dd[i] || !p[i])
			continue;
		dd[i] = 1;
		dfs1(i);
	}
}

void calc(int x, int y) {
	if (x == n + 1 && y != k)
		return;
	if (y == k) {
		int id = 0;
		for (int i = 1; i <= n; i++)
			if (p[i])
				cc[++id] = i;
		for (int i = 1; i <= n; i++)
			dd[i] = 0;
		dd[cc[1]] = 1;
		dfs1(cc[1]);
		for (int i = 1; i <= id; i++) {
			if (dd[cc[i]] == 0) {
				dd[cc[i]] = 1;
				dfs1(cc[i]);
				break;
			}
		}
		for (int i = 1; i <= id; i++)
			if (!dd[cc[i]])
				return;
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i])
				continue;
			int minn = (1 << 30);
			for (int j = 1; j <= id; j++)
				minn = min(minn, dist[i][cc[j]]);
			maxx = max(maxx, minn);
		}
		if (ans > maxx)
			ans = min(ans, maxx);
		return;
	}
	p[x] = 1;
	calc(x + 1, y + 1);
	p[x] = 0;
	calc(x + 1, y);
}

void solve() {
	for (int i = 1; i <= n; i++)
		node[i].clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = 0;
		p[i] = 0;
	}
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	init();
	calc(1, 0);
	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	for (int i = 1; i <= T; i++)
		solve();
	return 0;
}