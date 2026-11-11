#include <bits/stdc++.h>
using namespace std;
const int N = 805, M = 5e5+5;
long long dis[N][N], jb[M], a[M], t[M], st[M];
vector<int> g[M];
bool vis[M];
struct node{
	int u, dep;
};
int dfs(int s, int e, int m){
	for(int i = 1; i <= m; i++) vis[i] = false;
	queue<node> q;
	q.push({s, 0});
	while(!q.empty()){
		int u = q.front().u, dep = q.front().dep;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		if(u == e) return dep;
		int len = g[u].size();
		for(int i = 0; i < len; i++){
			int v = g[u][i];
			if(vis[v]) continue;
			q.push({v, dep+1});
		}
	}
	return -1;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int bh, n, m, d, q;
	cin >> bh >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> jb[i];
	if(m <= 800){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++) dis[i][j] = 1e18;
			dis[i][i] = 0;
		}
	}
	bool tsame = true;
	long long t1 = 0;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			st[j] = st[j-1]+t[j];
			if(j > 1 && t[j] != t[j-1]) tsame = false;
		}
		for(int x = 1; x < k; x++){
			for(int y = x+1; y <= k; y++){
				if(m <= 800) dis[a[x]][a[y]] = dis[a[y]][a[x]] = min(dis[a[x]][a[y]], t[x]+t[y]);
				g[a[x]].push_back(a[y]);
				g[a[y]].push_back(a[x]);
			}
		}
		t1 = t[k];
	}
	if(m <= 800){
		for(int k = 1; k <= m; k++){
			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= m; j++){
					dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int u, v;
			cin >> u >> v;
			long long ans = dis[u][v]+jb[u]+jb[v];
			cout << ans << '\n';
		}
		return 0;
	}
	if(tsame){
		while(q--){
			int u, v;
			cin >> u >> v;
			long long ans = 2ll*dfs(u, v, m)*t1+jb[u]+jb[v];
			cout << ans << '\n';
		}
		return 0;
	}
	return 0;
}
// 32~48pts
