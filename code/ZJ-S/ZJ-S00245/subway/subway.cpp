#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int w[N];
int G[N][505]; // 第i站在j号线的点权 
long long res;
int vis[N];
int viss[N];
vector<int> H[N]; // i号点在的线 
vector<int> E[N]; // i号线有的点 
void dfs(int p, int q, long long step, int f) {
	for(auto it : H[p]) {
		for(auto its : H[q]) {
			if(it == its) {
				res = min(res, step + G[q][it]);
				return ;
			}
		}
	}
	if(step >= res) return ;
	for(auto op : H[p]) {
		for(auto it : E[op]) {
			if(!vis[it]) {
				vis[it] = 1;
				if(op != f) dfs(it, q, step + G[it][op] + G[p][op], op);
				else dfs(it, q, step + G[it][op], op);
				vis[it] = 0;
			}
		}
	}
	
//	if(step >= res) return ;
//	for(auto op : H[p]) {
//		if(!viss[op]) {
//		viss[op] = 1;
//		for(auto it : E[op]) {
//			if(!vis[it] && H[it].size() > 1) {
//				vis[it] = 1;
//				dfs(it, q, step + G[it][op] + G[p][f], op);
//				vis[it] = 0;
//			}
//		}
//		}
//	}
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int u, t;
			cin >> u >> t;
			H[u].push_back(i);
			E[i].push_back(u);
			G[u][i] = t;
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		res = INT_MAX;
		for(auto it : H[x]) {
			for(int i = 1; i <= m; i++) vis[i] = viss[i] = 0;
			dfs(x, y, G[x][it], it);
		}
		res += w[x] + w[y];
		cout << res << '\n';
	}
	return 0;
}
