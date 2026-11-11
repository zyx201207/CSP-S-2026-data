#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define pi pair<int, int>
const int maxn = 15;
const int inf = 4e18;
int n, k;
vector<int> g[maxn];
int min_dis = inf;
int chi[maxn], vst[maxn];
inline void fnd(int x){
	if(vst[x] == 1) return ;
	vst[x] = 1;
	
	for(int v : g[x]){
		if(chi[v]) fnd(v);
	}
}
inline int check(){
	memset(vst, 0, sizeof(vst));
	int num = 0;
	for(int i = 1; i <= n; i++){
		if(chi[i] && !vst[i]) fnd(i), num++;
		
//		if(chi[3] == 1 && chi[4] == 1 && chi[10] == 1){
//			printf("i:%d\n", i);
//			for(int j = 1; j <= n; j++){
//				printf("\tchi[%d]:%d, ", j, chi[j]);
//			}
//			printf("\n");
//			for(int j = 1; j <= n; j++){
//				printf("\tvst[%d]:%d, ", j, vst[j]);
//			}
//			printf("\n");
//		}
	}
	
	return num;
}
int dis[maxn][maxn], vis[maxn];
inline void dijkstra(int st){
	memset(vis, 0, sizeof(vis));
	priority_queue<pi, vector<pi>, greater<pi> > q;
	q.push({0, st});
	dis[st][st] = 0;
	
	while(!q.empty()){
		int u = q.top().second; q.pop();
		
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(int v : g[u]){
			if(dis[st][v] > dis[st][u] + 1){
				dis[st][v] = dis[st][u] + 1;
				q.push({dis[st][v], v});
			}
		}
	}
}
inline void dfs(int x, int num){
	if(x == n + 1){
		if(num != k) return ;
		
		int nb = check();
		if(nb > 2) return ;
		
//		for(int i = 1; i <= n; i++){
//			printf("chi[%d]:%d, ", i, chi[i]);
//		}
//		printf("\n");
		
		memset(dis, 0x3f, sizeof(dis));
		for(int i = 1; i <= n; i++){
			dijkstra(i);
		}
		
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= n; j++){
//				cout << dis[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		
		int rm = 0;
		for(int i = 1; i <= n; i++){
			int d = inf;
			for(int j = 1; j <= n; j++){
				if(!chi[j]) continue;
				
				d = min(d, dis[i][j]);
			}
			rm = max(rm, d);
		}
		
//		if(rm == 1){
//			for(int i = 1; i <= n; i++){
//				printf("chi[%d]:%d, ", i, chi[i]);
//			}
//			printf("nb:%d\n", nb);
//			printf("\n");
//		}
		
		min_dis = min(min_dis, rm);
		return ;
	}
	
	if(num + (n - x + 1) < k) return ;
	
	for(chi[x] = 0; chi[x] <= 1; chi[x]++) dfs(x + 1, num + chi[x]);
}
inline void solve(){
	min_dis = inf;
	
	for(int i = 1; i <= n; i++) g[i].clear();
	
	cin >> n >> k;
	for(int i = 1; i <= n - 1; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	
	dfs(1, 0);
	
	cout << min_dis << '\n';
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, T; cin >> c >> T;
	while(T--) solve();
	return 0;
}
