#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int c, T, n, K;
int dfn[N], st[24][N], lg[N], dep[N], timer, siz[N], hei[N], seq[N];
int f[N];
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
vector<int> G[N];
inline int get(int x, int y) {
	return (dfn[x] < dfn[y]) ? x : y;
}
void dfs(int u, int fa) {
	dfn[u] = ++timer;
	st[0][timer] = fa;
	seq[timer] = u;
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	hei[u] = 0;
	for (auto v: G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		hei[u] = max(hei[u], hei[v] + 1);
	}
}
inline int lca(int x, int y) {
	if (x == y) return x;
	x = dfn[x]; y = dfn[y];
	if (x > y) swap(x, y);
	int t = lg[y - x];
	return get(st[t][x + 1], st[t][y - (1 << t) + 1]);
}
inline int dist(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
void solvebf() {
	int ans = n + 1;
	for (int i = 0; i < (1 << n); i ++) {
		for (int j = 1; j <= n; j ++) f[j] = j;
		int cnt = 0;
		for (int j = 0; j < n; j ++) {
			if ((i >> j) & 1) {
				cnt ++;
			}
		}
		if (cnt != K) continue;
		for (int j = 0; j < n; j ++) {
			if ((i >> j) & 1) {
				for (auto k: G[j + 1]) {
					if ((i >> (k - 1)) & 1) {
						int rj = find(j + 1), rk = find(k);
						if (rj != rk) {
							f[rj] = rk;
							cnt --;
						}
					}
				}
			}
		}
		if (cnt != 2) continue;
		int cur = 0;
		for (int k = 1; k <= n; k ++) {
			int now = n + 1;
			for (int j = 0; j < n; j ++)
				if ((i >> j) & 1)
					now = min(now, dist(j + 1, k));
			cur = max(cur, now);
		}
		ans = min(ans, cur);
	}
	printf("%d\n", ans);
}
//int dp[1005][1005];
//void dfs1(int u, int fa) {
	//if (G[u].size() == 1 && u != 1)
		//dp[u][1] = 0;
	//for (auto v: G[u]) {
		//if (v == fa) continue;
		//dfs1(v, u);
		//for (int k = 1; k <= siz[u]; k ++) {
			//for (int j = min(k, siz[v]); j >= 1; j --) {
			////for (int j = 1; j <= min(k, siz[v]); j ++) {
				//dp[u][k] = min(dp[u][k], max(dp[u][k - j], dp[v][j]));
			//}
		//}
	//}
//}
//void solve2() {
	//int ans = n + 1;
	//for (int x = 1; x <= n; x ++) {
		//dp[x][0] = hei[x];
		//for (int i = 1; i <= siz[x]; i ++)
			//dp[x][i] = n + 1;
	//}
	////for (int i = 1; i <= n; i ++)
		////printf("seq[%d] = %d\n", i, seq[i]);
	////for (int x = 1; x <= n; x ++) {
		////printf("Calculating Root #%d\n", x);
		////priority_queue<int> heap;
		//////vector<int> vec;
		////for (int i = dfn[x]; i <= dfn[x] + siz[x] - 1; i ++) {
			//////vec.push_back(hei[seq[i]] + 1);
			////heap.push(dist(x, seq[i]));
			////printf("dist(%d, %d): %d\n", x, seq[i], dist(x, seq[i]));
		////}
		//////sort(vec.begin(), vec.end(), greater<int>());
		//////printf("hei sequence: ");
		//////for (auto it: vec)
			//////printf("%d ", it);
		//////printf("\n");
		////dp[x][siz[x]] = 0;
		////for (int j = 1; j <= siz[x]; j ++) {
			////int di = heap.top(); heap.pop();
			////heap.push(di - 1);
			////dp[x][j] = heap.top();
			//////dp[x][j] = vec[j];
			////printf("dp[%d][%d] = %d\n", x, j, dp[x][j]);
		////}
	////}
	//dfs1(1, 0);
	//for (int x = 1; x <= n; x ++) {
		//dp[x][0] = hei[x];
		//for (int i = 1; i <= siz[x]; i ++)
			//printf("dp[%d][%d] = %d\n", x, i, dp[x][i]);
	//}
	//for (int x = 1; x <= n; x ++) {
		//for (int y = 1; y <= n; y ++) {
			//if (!(dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + siz[x] - 1)) {
				//int cur = 0;
				//for (int i = 1; i <= n; i ++) {
					//if (!(dfn[x] <= dfn[i] && dfn[i] <= dfn[x] + siz[x] - 1)
					//&& !(dfn[y] <= dfn[i] && dfn[i] <= dfn[y] + siz[y] - 1)) {
						//cur = max(cur, min(dist(i, x), dist(i, y)));
					//}
				//}
				//for (int i = 1; i < K; i ++) {
					////printf("(%d, %d) %d, (%d, %d) %d, %d\n", x, i, dp[x][i], y, K - i, dp[y][K - i], cur);
					//if (i <= siz[x] && K - i <= siz[y]) {
						////printf("(%d, %d) %d, (%d, %d) %d, %d\n", x, i, dp[x][i], y, K - i, dp[y][K - i], cur);
						//ans = min(ans, max(max(dp[x][i], dp[y][K - i]), cur));
					//}
				//}
			//}
		//}
	//}
	//printf("%d\n", ans);
//}
inline void solve() {
	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; i ++)
		G[i].clear();
	timer = 0;
	for (int i = 2; i <= n; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		lg[i] = lg[i / 2] + 1;
	}
	dfs(1, 0);
	for (int i = 1; i <= lg[n]; i ++)
		for (int u = 1; u + (1 << i) - 1 <= n; u ++)
			st[i][u] = get(st[i - 1][u], st[i - 1][u + (1 << (i - 1))]);
	//if (n <= 10) {
		solvebf();
	//} else {
		//solve2();
	//}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d %d", &c, &T);
	while (T--) solve();
	return 0;
}
