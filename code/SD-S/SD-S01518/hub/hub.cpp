#include<bits/stdc++.h>
using namespace std;
int c , t , n , k;
int tot = -1 , ans;
int head[15] , ver[35] , ne[35];
int dis[15][15];
bool flag[15] , vis[15];
void add(int x , int y) {
	tot++;
	ver[tot] = y;
	ne[tot] = head[x];
	head[x] = tot;
}
void dfs(int u) {
	vis[u] = 1;
	for(int i = head[u] ; i != -1 ; i = ne[i]) {
		int v = ver[i];
		if(flag[v] && !vis[v]) dfs(v);
	}
}
bool check() {
	int cnt = 0;
	memset(vis , 0 , sizeof vis);
	for(int i = 1 ; i <= n ; i++) {
		if(flag[i] && !vis[i]) {
			cnt++;
			dfs(i);
		}
	}
	return (cnt <= 2);
}
void solve(int step) {
	if(step == k + 1) {
		if(check()) {
			int res = 0;
			for(int i = 1 ; i <= n ; i++) {
				int tmp = 0x3f3f3f3f;
				for(int j = 1 ; j <= n ; j++) {
					if(flag[j] == 1) tmp = min(tmp , dis[i][j]);
				}
				res = max(res , tmp);
			}
			ans = min(ans , res);
		}
		return;
	}
	for(int i = 1 ; i <= n ; i++) {
		if(!flag[i]) {
			flag[i] = 1;
			solve(step + 1);
			flag[i] = 0;
		} 
	}
}
int main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	while(t--) {
		memset(head , -1 , sizeof head);
		memset(dis , 0x3f , sizeof dis);
		tot = -1 , ans = 0x3f3f3f3f;
		cin >> n >> k;
		if(n <= 10) {
			for(int i = 1 ; i < n ; i++) {
				int u , v;
				cin >> u >> v;
				add(u , v);
				add(v , u);
				dis[u][v] = dis[v][u] = 1;
			}
			for(int i = 1 ; i <= n ; i++) dis[i][i] = 0;
			for(int k = 1 ; k <= n ; k++) {
				for(int i = 1 ; i <= n ; i++) {
					for(int j = 1 ; j <= n ; j++) {
						dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
					}
				}
			}
			solve(1);
			cout << ans << "\n";
		}else {
			cout << 1 << "\n";
		}
	}
	return 0;
}
