#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int c, n, k, T, ans, dis[N], tag[N], fa[N];
vector<int> e[N];
int find(int x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
void dfs(int u, int fa, int dep){
	dis[u] = min(dis[u], dep);
	for(int v : e[u]){
		if(v == fa) continue;
		dfs(v, u, dep + 1);
	}
}
void gettag(int x, int cnt){
	if(cnt > k) return;
	if(x > n){
		if(cnt < k) return;
		for(int i = 1; i <= n; i++) dis[i] = n, fa[i] = i;
		for(int i = 1; i <= n; i++){
			if(tag[i]){
				dfs(i, 0, 0);
				for(int j : e[i]){
					if(!tag[j]) continue;
					int x = find(j), y = find(i);
					if(x == y) continue;
					fa[x] = y, cnt--;
				}
			}
		}
		if(cnt > 2) return;
		int res = 0;
		for(int i = 1; i <= n; i++) res = max(res, dis[i]);
		ans = min(ans, res);
		return;
	}
	tag[x] = 1;
	gettag(x + 1, cnt + 1);
	tag[x] = 0;
	gettag(x + 1, cnt);
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		e[u].emplace_back(v), e[v].emplace_back(u);
	}
	if(c <= 3){
		ans = n;
		gettag(1, 0);
		cout << ans << '\n';
	}
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
/*
应该是可以二分的，但是没有时间细想了 

这模拟也太难了 

0 1
5 2
1 2
2 3
3 4
4 5

18:11 15pts
*/
