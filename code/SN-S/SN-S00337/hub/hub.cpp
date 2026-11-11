// by 0x0F
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3fll;
int C;
int n, k;
struct Node {
	int to, next;
} edge[2000010];
int head[1000010], tot;
void add(int u, int v) {
	edge[++tot].to = v;
	edge[tot].next = head[u], head[u] = tot;
}
int dp[110][110][110];
int fa[50], ins[50];
int query(int u) {
	if (fa[u] == u) return u;
	return fa[u] == query(fa[u]);
}
int cnt[50];
int ds[50][50], dis[50];
void dfs(int u, int fa, int s) {
	for (int i = head[u]; i; i = edge[i].next) {
		int v = edge[i].to;
		if (v == fa) continue;
		ds[s][v] = ds[s][u] + 1;
		dfs(v, u, s);
	}
}
void bf1() {
	int Ans = inf;
	for (int b = 1; b < (1 << n); b++) {
		if (__builtin_popcount(b) != k) continue;
		for (int i = 1; i <= n; i++) ins[i] = 0;
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) ins[i] = (b >> i - 1) & 1;
		for (int i = 1; i <= n; i++)
			if (ins[i]) {
				for (int x = head[i]; x; x = edge[x].next) {
					int j = edge[x].to;
					if (!ins[j]) continue;
					int u = query(i), v = query(j);
					if (u != v) continue;
					fa[u] = v;
				}
			}
		for (int i = 1; i <= n; i++) if(ins[i]) cnt[query(i)] = 1;
		int tt = 0;
		for (int i = 1; i <= n; i++) tt += cnt[i];
		if (tt > 2) continue;
		for (int i = 1; i <= n; i++) dis[i] = inf;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) ds[i][j] = inf;
		for (int i = 1; i <= n; i++) {
			ds[i][i] = 0;
			dfs(i, 0, i); 
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (ins[i]) dis[i] = 0;
			for (int j = 1; j <= n; j++)
				if (ins[j]) dis[i] = min(dis[i], ds[i][j]);
			ans = max(ans, dis[i]);
		}
		Ans = min(Ans, ans); 
	}
	cout << Ans << endl;
}
void init() {
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1; i <= tot; i++) edge[i].to = edge[i].next = 0;
	tot = 0;
}
void solve() {
	n, k; cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		add(u, v), add(v, u);
	}
	if (n <= 10) bf1();
	init();
}
signed main() {
	ios::sync_with_stdio(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int T = 1;
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
