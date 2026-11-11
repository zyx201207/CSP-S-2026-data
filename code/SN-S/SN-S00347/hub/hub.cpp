//SN-S00347 王欣甜 西安市铁一中学
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 15;
int n, k;
vector <int> vc[maxn];
int f[maxn], d[maxn], vis[maxn];
int cnt;
void dfs(int u, int fa) {
	for(int v : vc[u]) {
		if(v == fa)continue;
		dfs(v, u);
		d[u] = min(d[u], d[v] + 1);
	}
}
void dfs1(int u, int fa) {
	for(int v : vc[u]) {
		if(v == fa)continue;
		d[v] = min(d[v], d[u] + 1);
		dfs1(v, u);
	}
}
void check(int u, int fa) {
	for(int v : vc[u]) {
		if(v == fa || d[v] != 0 || vis[v])continue;
		cnt++;
		vis[v] = 1;
		check(v, u);
	}
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)vc[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	int ans = inf;
	for(int i = 0; i < (1 << n); i++) {
		cnt = 0;
		for(int j = 0; j < n; j++)if((i >> j) & 1)cnt++;
		if(cnt != k)continue;
		memset(d, 0x3f, sizeof(d));
		for(int j = 0; j < n; j++)if((i >> j) & 1)d[j + 1] = 0;
		cnt = 1;
		memset(vis, 0, sizeof(vis));
		for(int j = 1; j <= n; j++)if(d[j] == 0 && !vis[j])check(j, 0);
		if(cnt == k)continue;
		cnt++;
		for(int j = 1; j <= n; j++)if(d[j] == 0 && !vis[j])check(j, 0);
		if(cnt != k)continue;
		dfs(1, 0);
		dfs1(1, 0);
		int res = 0;
		for(int i = 1; i <= n; i++)res = max(res, d[i]);
		ans = min(ans, res);
	}
	cout << ans << endl;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
}
