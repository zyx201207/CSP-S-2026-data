#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, mi, x, y;
int a[505][505], t[505][505];
bool vis[500005];
int g[505][505];
void dfs(int u, int k){
	if(u == y){
		mi = min(mi, k);
		return ;
	}
	for(int i = 0; i <= n; i++){
		if(vis[i] == 0 && g[x][i] != 0){
			vis[i] = 1;
			dfs(i, k + g[x][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++){
		int w;
		cin>>w;
		g[i][0] = w;
		g[0][i] = w;
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin>>k;
		for(int j = 1; j <= 2 * k; j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]][0] = t[i][j];
			g[0][a[i][j]] = t[i][j];
		}
	}
	
	for(int i = 1; i <= q; i++){
		cin>>x>>y;
		mi = INT_MAX;
		dfs(x, 0);
		cout<<mi<<"\n";
	}
	return 0;
}

