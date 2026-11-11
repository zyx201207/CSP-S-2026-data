#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[2000005], ans, sht;
bool f[2000005];
int ff = 0;
void dfs(int u, int v, int sum){
	if(u == v){
		if(sum == sht){
			ff++;
			return;
		}
		if(sht < sum)ff = 1;
		sht = min(sht, sum);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(u - i >= 1 && !f[u - i] && abs(x[u - i] - x[u]) <= d){
			f[u - i] = 1;
			dfs(u - i, v, sum + 1);
			f[u - i] = 0;
		}
		if(u + i <= n && !f[u + i] && abs(x[u + i] - x[u] <= d)){
			f[u + i] = 1;
			dfs(u + i, v, sum + 1);
			f[u + i] = 0;
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				sht = 1e9;
				for(int k = 1;k <= n;k++)f[k] = 0;
				ff = 0;
				f[i] = 1;
				dfs(i, j, 0);
				if(ff == 2)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
