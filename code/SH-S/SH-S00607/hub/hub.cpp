#include<bits/stdc++.h>
using namespace std;
vector<int> g[15];
int n, k;
bool used[15];
bool vis[15];
int dis[21];
void dfs(int u, int fa){
	for(int v : g[u]){
		if(v == fa || !used[v] || vis[v]) continue;
		vis[v] = 1;
		dfs(v, u);
	}
}
int bfs(){
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		dis[i] = 0;
		if(used[i]){
			q.push(i);
			dis[i] = 0;
			vis[i] = 1;
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : g[u]){
			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
				dis[v] = dis[u] + 1;
			}
		}
	}
	int maxn = -1;
	for(int i = 1; i <= n; i++){
		maxn = max(maxn, dis[i]);
	}
	return maxn;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if(c <= 3){
		while(t--){
			cin >> n >> k;
			for(int i = 1; i <= n; i++){
				g[i].clear();
			}
			for(int i = 1; i < n; i++){
				int u, v;
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			int ans = 1e8;
			for(int i = 0; i < (1 << n); i++){
				memset(vis, 0, sizeof(vis));
				int cnt = 0;
				for(int j = 1; j <= n; j++){
					if(i & (1 << (j - 1))){
						used[j] = 1;
						cnt++;
					}else used[j] = 0;
				}
				if(cnt != k) continue;
				cnt = 0;
				for(int j = 1; j <= n; j++){
					if(used[j]){
						vis[j] = 1;
						dfs(j, 0);
						cnt++;
						break;
					}
				}
				for(int j = 1; j <= n; j++){
					if(used[j] && !vis[j]){
						vis[j] = 1;
						dfs(j, 0);
						cnt++;
						break;
					}
				}
				if(cnt != 2) continue;
				bool flag = 0;
				for(int j = 1; j <= n; j++){
					if(used[j] && !vis[j]){
						flag = 1;
					}
				}
				if(flag) continue;
				ans = min(ans, bfs());
			}
			cout << ans << endl;
		}
	}
} 
/*
LUOGU UID 1549034

ίχίχίχ 
*/ 
