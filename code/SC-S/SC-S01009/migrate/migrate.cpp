#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int c, t;
int x[N];

int g[N][N];

int dist[N], vis[N];
int f[N];

int ans;
int n, m;
void work(int ii, int jj){
	for(int i = 1;i <= n;i ++){
		dist[i] = 1e9;
		vis[i] = 0;
		f[i] = 0;
	}
 	dist[ii] = 0;
	for(int i = 1;i <= n;i ++){
		int t = -1;
		for(int j = 1;j <= n;j ++){
			if(!vis[j] && (t == -1 || dist[t] > dist[j])){
				t = j;
			}
		}
		vis[t] = 1;
		for(int j = 1;j <= n;j ++){
			if(!vis[j] && dist[j] > dist[t] + g[t][j]){
				dist[j] = dist[t] + g[t][j];
				f[j] = 1;
			}
			else if(!vis[j] && dist[j] == dist[t] + g[t][j]){
				f[j] ++;
			}
		}
	}
	if(f[jj] == 2){
		ans ++;
	}
	return ;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t --){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i ++){
			scanf("%d", &x[i]);
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				g[i][j] = 1e9;
			} 
		}
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				if(x[j] - x[i] <= m){
					g[i][j] = 1;
				}
			} 
		}
		ans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				work(i, j);
			}
		}
		printf("%d\n", ans); 
	}
	
	
	return 0; 
}