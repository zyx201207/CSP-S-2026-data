#include<bits/stdc++.h>
using namespace std;
int c, t;
vector<int> e[100005];
int f[100005][30], dep[100005];
int n, k;
void dfs(int p, int fa) {
	f[p][0] = fa;
	dep[p] = dep[fa] + 1;
	for(int i : e[p]) if(i != fa) dfs(i, p);
}
void init() {
	for(int i = 1; i <= 25; i++) {
		for(int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		} 
	}
}
int ask(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 25; i >= 0; i--) {
		if(dep[f[u][i]] >= dep[v]) u = f[u][i];
	}
	for(int i = 25; i >= 0; i--) {
		if(f[u][i] != f[v][i]) {
			u = f[u][i], v = f[v][i];
		}
	}
	return f[u][0];
}
void solve() {
	cin >> n >> k;
	memset(f, 0, sizeof f);
	memset(dep, 0, sizeof dep);
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	init();
	int ans = 0x7f7f7f7f;
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int ss = -1;
			for(int k = 1; k <= n; k++) {
				int s = min(dep[k] + dep[i] - 2 * dep[ask(i, k)], dep[k] + dep[i] - 2 * dep[ask(j, k)]);
				ss = max(ss, s);
			}
			ans = min(ans, ss);
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
