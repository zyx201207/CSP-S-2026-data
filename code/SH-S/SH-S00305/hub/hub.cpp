#include <bits/stdc++.h>
using namespace std;

void dfsdis(int s, int u, int parent){
	for (auto v: g[u]){
		if (v == parent) continue;
		dis[s][v] = dis[s][u]+1;
		dfs(s, v, u);
	}
}

bool check(int a[]){
	int cnt = 0;
	for (int i = )
}

void dfs(int step){
	if (step > k){
		if (check(a)){
			
		}
		return;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		vis[i] = true;
		a[step] = i;
		dfs(step+1);
		vis[i] = false;
	}
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n-1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		dfsdis(i, i, 0);
	}
	dfs(1);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}
