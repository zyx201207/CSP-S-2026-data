#include <bits/stdc++.h>
using namespace std;
int c , n , m , d , q , ans = 0x3fff;
int w[10005], k , a[10005][10005], t[10005][10005], id[10005];
vector<int> g[10005];
bool vis[10005];
int x , y;
void dfs(int u , int sum){
	if(u == y){
		ans = min(ans , sum);
	}
	for(int i = 0; i < g[u].size(); i++){
		if(!vis[i]){
			if(id[u] != id[i]){
				int cc = sum + a[id[u]][i] + a[id[i]][i];
				dfs(i , cc);
			}else{
				dfs(i , sum);
			}
		}
	}
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n  >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n;i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
			if(!id[a[i][j]]){
				id[a[i][j]] = i;
			}
		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= k; j++){
//				cout << a[i][j] << t[i][j];
//			}
//			cout << endl;
//		}
		for(int j = 1; j <= k; j++){
			for(int z = j + 1; z <= k; z++){
				g[a[i][j]].push_back(a[i][z]);
				g[a[i][z]].push_back(a[i][j]);
			}
		}
	}

	for(int i = 0; i <= q; i++){
		cin >> x >> y;
		dfs(x, 0);
		cout << ans + w[x] + t[x][x] << endl;
	}
	return 0;
}
