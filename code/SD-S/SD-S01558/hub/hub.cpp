#include <bits/stdc++.h>
using namespace std;

namespace Subtask1{
	struct Edge{
		int x, y;
	}edge[1000005];
	
	int n, k, tong[1000005];
	vector<pair<int, int> > g[1000005];
	
	int MAXN, MAXNID, fa[1000005], dep[1000005];
	
	void dfs(int u, int par, int id, int d){
		fa[u] = par;
		if(MAXN < d){
			MAXN = d; MAXNID = u;
		}
		for(auto it : g[u]){
			if(it.first == par || it.second == id) continue;
			dfs(it.first, u, id, d + 1);
		}
	}
	
	void Dfs(int u, int par, int id){
		dep[u] = 1;
		for(auto it : g[u]){
			if(it.first == par || it.second == id) continue;
			Dfs(it.first, u, id);
			dep[u] = max(dep[u], dep[it.first] + 1);
		}
		if(par) tong[dep[u]]++;
		
//		if(id == 1){
//			cout << "??????????????????? " << u << " " << dep[u] << endl;
//		}
	}
	
	void get_res(int u, int id){
		MAXN = -1, MAXNID = 0;
		dfs(u, 0, id, 0);
		MAXN = -1;
		dfs(MAXNID, 0, id, 0);
		
		int rt = MAXNID;
		for(int i = 1; i <= MAXN / 2; i++) rt = fa[rt];
//		if(id == 1){
//			cout << "??????  find_rt " << rt << endl;
//		}
		
		Dfs(rt, 0, id);
	}
	void solve(){
		cin >> n >> k;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i < n; i++){
			int x, y;
			cin >> x >> y;
			g[x].push_back(make_pair(y, i));
			g[y].push_back(make_pair(x, i));
			edge[i] = {x, y};
		}
		
		int ans = n;
		for(int i = 1; i < n; i++){
			for(int j = 0; j <= n; j++) tong[j] = 0;
			get_res(edge[i].x, i);
			get_res(edge[i].y, i);
			
//			if(i == 1){
//				cout << "tong: ";
//				for(int j = 0; j <= n; j++) cout << tong[j] << " ";
//				cout << endl;
//			}
//			
			int nw = k - 2;
			for(int j = n; j >= 0; j--){
				if(tong[j] > nw){
					ans = min(ans, j);
					break;
				} else {
					nw -= tong[j];
				}
			}
		}
		cout << ans << "\n";
	}
	void Solve(int t){
		while(t--) solve();
		exit(0);
	}
}

namespace Subtask2{
	struct node{
		int x, y;
	}edge[1000005];
	
	node st[22][1000005];
	int lca[22][1000005];
	int lg[1000005], n;
	int sz[1000005], dep[1000005], k, dfnval[1000005], dfnpos[1000005];
	vector<int> g[1000005];
	int dfntot;
	
	void dfs(int x, int par){
		dfnpos[x] = ++dfntot;
		dfnval[dfntot] = x;
		sz[x] = 1;
		dep[x] = dep[par] + 1;
		
		for(auto it : g[x]){
			if(it == par) continue;
			dfs(it, x);
			sz[x] += sz[it];
			sz[x]++;
			
			dfnval[++dfntot] = x;
		}
	}
	int Ask(int x, int y){
		return (dep[x] < dep[y] ? x : y);
	}
	
	int LCA(int x, int y){
		if(dfnpos[x] > dfnpos[y]) swap(x, y);
		int l = dfnpos[x], r = dfnpos[y];
		int k = lg[r - l + 1];
		
		return Ask(lca[k][l], lca[k][r - (1 << k) + 1]);
	}
	
	int get_dis(int x, int y){
		int l = LCA(x, y);
		return dep[y] + dep[x] - dep[l] * 2;
	}
	
	void upd(node &res, int x, int y){
		if(get_dis(res.x, res.y) < get_dis(x, y)){
			res = {x, y};
		}
	}
	
	node Merge(node x, node y){
		node res = {x.x, x.y};
		upd(res, x.x, y.x);
		upd(res, x.x, y.y);
		upd(res, x.y, y.x);
		upd(res, x.y, y.y);
		upd(res, y.x, y.y);
		return res;
	}
	
	node Query(int l, int r){
		int k = lg[r - l + 1];
		return Merge(st[k][l], st[k][r - (1 << k) + 1]);
	}
	
	void solve(){
		dfntot = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			edge[i] = {u, v};
		}
		dfs(1, 0);
		for(int i = 1; i <= dfntot; i++) lca[0][i] = dfnval[i];
		for(int j = 1; j <= 20; j++){
			for(int i = 1; i + (1 << j) - 1 <= dfntot; i++){
				lca[j][i] = Ask(lca[j - 1][i], lca[j - 1][i + (1 << (j - 1))]);
			}
		}
		
		
		for(int i = 1; i <= dfntot; i++) st[0][i] = (node){dfnval[i], dfnval[i]};
		for(int j = 1; j <= 20; j++){
			for(int i = 1; i + (1 << j) - 1 <= dfntot; i++){
				st[j][i] = Merge(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			}
		}
		
		int ans = n;
		for(int i = 1; i < n; i++){
			int x = edge[i].x, y = edge[i].y;
			if(dep[x] < dep[y]) swap(x, y);
			
			node resa = Query(dfnpos[x], dfnpos[x] + sz[x] - 1);
			node resb;
			if(dfnpos[x] == 1) resb = Query(dfnpos[x] + sz[x], dfntot);
			else if(dfnpos[x] + sz[x] == dfntot + 1) resb = Query(1, dfnpos[x] - 1);
			else resb = Merge(Query(1, dfnpos[x] - 1), Query(dfnpos[x] + sz[x], dfntot));
			
			int lena = get_dis(resa.x, resa.y);
			int lenb = get_dis(resb.x, resb.y);
			
			ans = min(ans, max((lena + 1) / 2, (lenb + 1) / 2)); 
		}
		cout << ans << "\n";
	}
	void Solve(int t){
		for(int i = 2; i <= 1000000; i++) lg[i] = lg[(i >> 1)] + 1;
		while(t--) solve();
		exit(0);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	if(c <= 10) Subtask1::Solve(t);
	else Subtask2::Solve(t);
	return 0;
}
