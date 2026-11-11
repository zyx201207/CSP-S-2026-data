#include<bits/stdc++.h>
using namespace std;
int c, t, n, k, u, v, now, ji, cnt, fa[11], dep[11], fcnt, _sum, sum, ans;
vector<int> bian[11];
bool vis[11], dis[11][11];
int find(int a){
	return fa[a] == a ? a : fa[a] = find(fa[a]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b)return;
	fa[b] = a, fcnt--;
}
void dfs(int now, int fa){
	if(now != fa)dep[now] = dep[fa] + 1;
	if(vis[now])_sum = min(_sum, dep[now]);
	for(int nxt : bian[now]){
		if(nxt == fa)continue;
		dfs(nxt, now);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		ans = 0x3f3f3f3f, cnt = 0;
		memset(dis, false, sizeof(dis));
		memset(vis, false, sizeof(vis));
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)bian[i].resize(0);
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			bian[u].push_back(v), dis[u][v] = true;
			bian[v].push_back(u), dis[v][u] = true;
		}
		for(int l = 1; l < 1 << n; l++){
			now = 1, ji = l;
			while(ji % 2 == 0)now++, ji /= 2;
			if(!vis[now])vis[now] = true, cnt++;
			else vis[now] = false, cnt--;
			if(cnt == k){
				fcnt = k;
				iota(fa + 1, fa + n + 1, 1);
				for(int i = 1; i <= n; i++){
					if(vis[i]){
						for(int j = 1; j <= n; j++){
							if(i != j && vis[j] && dis[i][j]){
								merge(i, j);
							}
						}
					}
				}
				if(fcnt > 2)continue;
				sum = 0;
				for(int i = 1; i <= n; i++){
					_sum = 0x3f3f3f3f;
					dep[i] = 0;
					dfs(i, i);
					sum = max(sum, _sum);
				}
				ans = min(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
