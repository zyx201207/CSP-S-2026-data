#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int c, T, n, k, root, maxx = -1, ans;
int head[N], num = 0;

struct edg {
	int nxt, to;
} edge[N * 2];

void init() {
	for (int i = 1; i <= num; i++) {
		edge[i].nxt = edge[i].to = 0;
	}
	memset(head, 0, sizeof(head));
	num = 0;
	maxx = -1;
}

void add(int from, int to) {
	edge[++num].nxt = head[from];
	edge[num].to = to;
	head[from] = num;
}

void dfs1(int x, int dep, int fa) {
	for (int i = head[x]; i != 0; i = edge[i].nxt) {
		if (edge[i].to == fa)
			continue;
		if (dep + 1 > maxx) {
			root = edge[i].to;
			maxx = dep + 1;
		}
		dfs1(edge[i].to, dep + 1, x);
	}
}

void dfs2(int x, int dep, int fa) {
	for (int i = head[x]; i != 0; i = edge[i].nxt) {
		if (edge[i].to == fa)
			continue;
		maxx = max(maxx, dep + 1);
		dfs2(edge[i].to, dep + 1, x);
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	root = 1;
	dfs1(1, 0, 0);
	dfs2(root, 0, 0);
	ans = (maxx + k) / (2 * k);
	cout << max(ans, 1) << "\n";
	init();
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
