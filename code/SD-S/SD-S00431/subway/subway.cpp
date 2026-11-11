#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int C, n, m, D, q, ans;
int W[N];
vector<pii> g[N];
vector<int> c[N], w[N];
int ciu[N];
int vis[N];
void dfs(int u, int id, int s, int e){
	if(s >= ans) return;
	if(u == e){
		int l = 0, r = c[u].size() - 1;
		while(l < r){
			int mid = l + r + 1 >> 1;
			if(c[u][mid] <= id) l = mid;
			else r = mid - 1;
		}
		ans = min(ans, s + w[u][l]);
		return;
	}
	for(pii t : g[u]){
		int v = t.first, idv = t.second;
		if(vis[v]) continue;
		vis[v] = 1;
		if(idv == id) dfs(v, id, s, e);
		else{
			int add = 0, l = 0, r = c[u].size() - 1;
			while(l < r){
				int mid = l + r + 1 >> 1;
				if(c[u][mid] <= idv) l = mid;
				else r = mid - 1;
			}
			add += w[u][l];
			l = 0, r = c[u].size() - 1;
			while(l < r){
				int mid = l + r + 1 >> 1;
				if(c[u][mid] <= id) l = mid;
				else r = mid - 1;
			}
			add += w[u][l];
			dfs(v, idv, s + add, e);
		}
		vis[v] = 0;
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++){
		cin >> W[i];
		c[i].push_back(0);
		w[i].push_back(0);
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x;
			cin >> ciu[j] >> x;
			c[ciu[j]].push_back(i);
			w[ciu[j]].push_back(x);
			if(j > 1){
				g[ciu[j - 1]].push_back({ciu[j], i});
				g[ciu[j]].push_back({ciu[j - 1], i});
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		for(int i = 1; i <= m; i++) vis[i] = 0;
		vis[x] = 1;
		ans = 1e18;
		dfs(x, 0, 0, y);
		ans += W[x] + W[y];
		cout << ans << '\n';
	}
	return 0;
}
