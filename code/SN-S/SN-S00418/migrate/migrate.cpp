#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int C,T;
int n,m;
int x[maxn];
int ans[maxn][maxn];
int dis[maxn][maxn];
void solve(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			ans[i][j] = 0;
			dis[i][j] = 100;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> x[i]; 
	}
	for(int i = 0;i < (1 << n);i++){
		vector <int> v;
		int now = 0;
		for(int j = 0;j < n;j++){
			if(i & (1 << j)){
				now++;
				v.push_back(j + 1);
			}
		}
		if(v.size() < 2){
			continue;
		}
		bool b = 0;
		for(int j = 1;j < v.size();j++){
			if(x[v[j]] - x[v[j - 1]] > m){
				b = 1;
			}
		}
		if(b){
			continue;
		}else{
			if(now < dis[v[0]][v.back()]){
				dis[v[0]][v.back()] = now;
				ans[v[0]][v.back()] = 1;
			}else if(now == dis[v[0]][v.back()]){
				ans[v[0]][v.back()]++;
			}
		}
	}
	int res = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(ans[i][j] == 2){
				res ++;
			}
		}
	}
	cout << res << endl;
}
signed main(){
	cin >> C >> T;
	while(T--){
		solve();
	}
}
