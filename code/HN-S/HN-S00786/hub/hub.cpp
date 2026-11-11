#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, ans = INT_MAX, maxn, maxi, p[100005], fa[100005], depth[100005], f[100005][20];
set<pair<int, int> > st;
vector<int> g[100005];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}
void init(int x, int fa){
	depth[x] = depth[fa] + 1;
	f[x][0] = fa;
	for(int i = 1; i <= 19; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for(auto i : g[x]){
		if(i == fa) continue;
		init(i, x);
	}
}
int lca(int x, int y){
	if(depth[x] < depth[y]) swap(x, y);
	for(int i = 19; i >= 0; i--){
		if(depth[f[x][i]] >= depth[y]) x = f[x][i];
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x, int y){
//	cout << x << " " << y << " " << lca(x, y) << "\n";
	return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}
void dfs(int step, int lst){
	if(step > k){
		for(int i = 1; i <= k; i++) fa[p[i]] = p[i];
//		for(int i = 1; i <= k; i++) cout << p[i] << " ";
//		cout << "\n";
		for(int i = 1; i <= k; i++){
			for(int j = i + 1; j <= k; j++){
				if(st.count({p[i], p[j]})) merge(p[i], p[j]);
			}
		}
		int cnt = 0;
		for(int i = 1; i <= k; i++) if(fa[p[i]] == p[i]) cnt++;
		if(cnt > 2) return;
		int maxn = 0;
		for(int i = 1; i <= n; i++){
			int minn = INT_MAX;
			for(int j = 1; j <= k; j++){
				minn = min(minn, dis(i, p[j]));
			}
			if(minn == INT_MAX) minn = 0;
			maxn = max(maxn, minn);
		}
		ans = min(ans, maxn);
		return;
	}
	for(int i = lst + 1; i <= n; i++){
		p[step] = i;
		dfs(step + 1, i);
	}
}
void dfs1(int x, int fa){
	depth[x] = depth[fa] + 1;
	if(depth[x] > maxn){
		maxn = depth[x];
		maxi = x;
	}
	for(auto i : g[x]){
		if(i == fa) continue;
		dfs1(i, x);
	}
}
void dfs2(int x, int fa){
	depth[x] = depth[fa] + 1;
	if(depth[x] > maxn){
		maxn = depth[x];
		maxi = x;
	}
	for(auto i : g[x]){
		if(i == fa) continue;
		dfs2(i, x);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		ans = INT_MAX;
		st.clear();
		for(int i = 1; i <= n; i++){
			g[i].clear(), depth[i] = 0;
			for(int j = 0; j <= 19; j++) f[i][j] = 0;
		}
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			st.insert({u, v});
			st.insert({v, u});
			g[u].push_back(v);
			g[v].push_back(u);
		}
		init(1, 0);
		dfs(1, 0);
		cout << ans << "\n";
	}
	return 0;
} 
