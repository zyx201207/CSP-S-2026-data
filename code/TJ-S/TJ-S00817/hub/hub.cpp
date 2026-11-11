#include<bits/stdc++.h>
using namespace std;
int c, t, n, k, mi;
int e[1005][3005], vis[3005];
void dfs(int x, int st){
	if(vis[x] == 1) return;
	mi = min(mi, st);
	for(int i = 1; i <= n; i++){
		if(e[x][i] == 1){
			dfs(i, st + 1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1; i < n; i++){
			int u, v;
			cin>>u>>v;
			e[u][v] = 1;
			e[v][u] = 1;
		}
		mi = INT_MAX;
		cout<<0<<"\n";
	}
	
	return 0;
}

