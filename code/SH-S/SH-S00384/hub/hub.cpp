#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int N1 = 35;
int c,T,n,k,fa[N],dis[N1][N1],dist[N1];
vector<int> G[N];
bool vis[N];
int getf(int x){
	if (x == fa[x]) return fa[x];
	return fa[x] = getf(fa[x]);
}
void merge(int u,int v){
	int p = getf(u),q = getf(v);
	if (p != q) fa[p] = q;
}
int check(int S){
	memset(vis,0,sizeof(vis));
	memset(fa,0,sizeof(fa));
	for (int i = 0;(1 << i) < S;i++){
		if (S & (1 << i)) vis[i + 1] = 1;
	}
	for (int i = 1;i <= n;i++){
		if (vis[i]) fa[i] = i;
	}
	for (int i = 1;i <= n;i++){
		if (vis[i]){
			for (int v : G[i]) if (vis[v]) merge(i,v);
		}
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++){
		if (vis[i] && getf(i) == i) cnt++;
	}
	if (cnt != 2) return 0x3f3f3f3f;
	memset(dist,0x3f,sizeof(dist));
	int res = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (j == i) continue;
			if (vis[j]) dist[i] = min(dist[i],dis[i][j]);
		}
		if (vis[i]) dist[i] = 0;
		res = max(res,dist[i]);
	}
	return res;
}
void solve(){
	cin >> n >> k;
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1;i <= n;i++) G[i].clear();
	for (int i = 1,u,v;i < n;i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u][v] = dis[v][u] = 1;
	}
	for (int i = 1;i <= n;i++) dis[i][i] = 0;
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for (int S = 0;S < (1 << n);S++){
		if (__builtin_popcount(S) == k) ans = min(ans,check(S));
	}
	cout << ans << '\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while (T--) solve();
}
