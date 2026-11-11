#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> g[2000005];
int dfs(int x, int dep) {
	if(x == n) return dep;
	dep += 1;
	int ans = dep;
	for(int i = 0; i < g[x].size(); i++){
		ans = max(ans, dfs(g[x][i], dep));
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i <= n; i++) {
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << dfs(1,0);
	}
	return 0;
}
