#include<bits/stdc++.h>
using namespace std;
int c, T, n, k, d[500010], f[500010][25], r[20], cnt;
bool vis[20];
vector<int> edges[500010];
inline void dfs(int x, int p){
	for(auto y : edges[x]){
		if(y != p){
			d[y] = d[x] + 1, f[y][0] = x;
			dfs(y, x);
		}
	}
}
int LCA(int u, int v){
	if(d[u] < d[v]){
		swap(u, v);
	}
	int len = d[u] - d[v];
	for(int i = 0; len; i++, len >>= 1){
		if(len & 1){
			u = f[u][i];
		}
	}
	if(u == v){
		return u;
	}
	for(int j = (int)(__lg(n)); j >= 0; j--){
		if(f[u][j] != f[v][j]){
			u = f[u][j], v = f[v][j];
		}
	}
	return f[u][0];
}
inline void tour(int x, int p){
	vis[x] = 1;
	for(auto y : edges[x]){
		if(r[y] && y != p){
			tour(y, x);
		}
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	for(; T--; ){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++){
			d[i] = 0;
			edges[i].clear();
			for(int j = 0; (1 << j) <= n; j++){
				f[i][j] = 0;
			}
		}
		for(int i = 1, u, v; i < n; i++){
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		d[1] = 1;
		dfs(1, 0);
		for(int j = 1; (1 << j) <= n; j++){
			for(int i = 1; i <= n; i++){
				f[i][j] = f[f[i][j - 1]][j - 1];
			}
		}
			int ans = 1 << 30;
			for(int S = 0; S < (1 << n); S++){
				if(__builtin_popcount(S) == k){
					for(int i = 0; i < n; i++){
						r[i + 1] = ((S >> i) & 1);
					}
					for(int i = 1; i <= n; i++){
						vis[i] = 0;
					}
					cnt = 0;
					for(int i = 1; i <= n; i++){
						if(r[i] && !vis[i]){
							cnt++;
							tour(i, f[i][0]);
						}
					}
					int maxn = 1 << 30;
					if(cnt <= 2){
						maxn = 0;
						for(int i = 1; i <= n; i++){
							if(!r[i]){
								int minn = 1 << 30;
								for(int j = 1; j <= n; j++){
									if(r[j]){
										minn = min(minn, d[i] + d[j] - d[LCA(i, j)] * 2);
									}
								}
								maxn = max(maxn, minn);
							}
						}
					}
					ans = min(ans, maxn);
				}
			}
			printf("%d\n", ans);
	}
	return 0;
}
