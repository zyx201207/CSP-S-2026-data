#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+5;
int c, T, n, k, dis[N]; bool vis[N], col[N]; vector<int> g[N];
void dfs(int u, int fa, int d){
	if (dis[u] <= d) return ; dis[u] = d;
	for (int v : g[u]) if (v != fa) dfs(v, u, d+1);
}
void dfs2(int u){ vis[u] = 1; for (int v : g[u]) if (col[v] && !vis[v]) dfs2(v); }
inline bool chk(int x){
	for (int msk = 0; msk < (1<<n); msk++){
		int tot = __builtin_popcount(msk);
		if (tot != k) continue;
		for (int i = 1; i <= n; i++) col[i] = (msk&(1<<i-1)), dis[i] = 1e9, vis[i] = 0;
		bool flg = 1; int idx = 0;
		for (int i = 1; i <= n; i++) if (col[i] && !vis[i]){
			if (++idx > 2){ flg = 0; break; } dfs2(i);
		} if (!flg) continue;
		for (int i = 1; i <= n; i++) if (col[i]) dfs(i, 0, 0);
		for (int i = 1; i <= n && flg; i++) if (dis[i] > x) flg = 0; 
		if (flg){
//			cout << x << ": ";
//			for (int i = 1; i <= n; i++) cout << col[i] << " "; cout << "\n";
			return 1;
		}
	} return 0;
}
signed main(){
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	cin >> c >> T; while (T--){
		cin >> n >> k;
		for (int i = 1; i < n; i++){
			int u, v; cin >> u >> v; g[u].push_back(v), g[v].push_back(u);
		} int l = 0, r = n, mid, ans;
		while (l <= r) mid = (l+r)/2, chk(mid) ? (r = mid-1, ans = mid) : (l = mid+1);
		cout << ans << "\n"; for (int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}

