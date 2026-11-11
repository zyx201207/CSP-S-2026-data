#include <bits/stdc++.h>
using namespace std;
#define int long long
int c , T , n , k , dis[2000005] , maxdis , cnt;
vector<int> e[2000005];
bool vis[2000005];
inline void dfs(int u , int fa){
	dis[u] = dis[fa]+1;
	maxdis = max(maxdis,dis[u]);
	for (auto v : e[u]) if (v != fa) dfs(v,u);
}
inline void dfs2(int u , int fa , int lst , int x){
	vis[u] = 1;
	if (dis[u]-dis[lst] == x+1) cnt++ , lst = u;
	for (auto v : e[u]) if (v != fa) dfs2(v,u,lst,x);
}
inline bool check(int x){
	cnt = 0;
	memset(vis,0,sizeof(vis));
	int C = 0;
	for (int i = 1 ; i <= n ; i++) if (!vis[i]) dfs2(i,-1,i-x+1,x) , C++;
	return cnt <= k && C <= 2;
}
inline void solve(){
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) e[i].clear();
	for (int i = 1 ; i < n ; i++){
		int u , v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	memset(dis,0x3f,sizeof(dis));
	dis[0] = 0;
	maxdis = 0;
	dfs(1,0);
	int l = 0 , r = maxdis , ans = maxdis;
	while (l <= r){
		int mid = l+r >> 1;
		if (check(mid)) ans = mid , r = mid-1;
		else l = mid+1;
	}
	cout << ans << '\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while (T--) solve();
	return 0;
}
