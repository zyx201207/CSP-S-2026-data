#include <bits/stdc++.h>
#define LL long long
#define INF 1e18
using namespace std;

const int N = 1e6 + 10;
int cid, T, dep[N];
int f[N][21];
int n, k;
bool vis[N];
vector<int> g[N];
int ans;
int pa[N];

int get(int x) {
	if(pa[x] == x) return x;
	return pa[x] = get(pa[x]); 
}

void merge(int x, int y) {
	pa[get(x)] = get(y); 
}

int lca(int x, int y) {
	if(dep[y] < dep[x]) swap(x, y);
	for(int i = 20;i >= 0;-- i){
		if(dep[y] - (1 << i) >= dep[x]) y = f[y][i];
	}
	if(x == y) return x;
	for(int i = 20;i >= 0;-- i){
		if(f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int dis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

void cal() {
	int ma = 0, cnt = 0;
	vector<int> ve;
	for(int i = 1;i <= n;++ i)
	 	if(vis[i]) ve.push_back(i);
	for(int i = 1;i <= n;++ i) pa[i] = i;
	for(int x : ve) {
		for(int y : g[x]) if(vis[y]) merge(x, y);
	}
	for(int i = 1;i <= n;++ i)
	if(get(i) == i && vis[i]) cnt++;
	if(cnt > 2) return;
	//cout << "\n";
	for(int i = 1;i <= n;++ i){
		if(vis[i]) continue;
		int mi = 2e9;
		for(int j : ve) mi = min(mi, dis(i, j));
		ma = max(ma, mi);
	}
	ans = min(ans, ma);
}

void dfs(int u, int mx) {
	if(u > k) {
		cal();
		return;
	}
	for(int i = mx;i <= n;++ i){
		if(!vis[i]) {
			vis[i] = 1;
			dfs(u + 1, i + 1);
			vis[i] = 0;
		}
	}
}

void dfs1(int u, int fa) {
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs1(v, u);
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> cid >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1;i <= n;++ i) g[i].clear(), dep[i] = 0;
		for(int i = 1;i < n;++ i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs1(1, 1);
		for(int j = 1;j <= 20;++ j)
			for(int i = 1;i <= n;++ i) f[i][j] = f[f[i][j - 1]][j - 1];
		ans = 2e9;
		dfs(1, 1);
		cout << ans << "\n";
	}
	return 0;
}