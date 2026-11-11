#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000001] , c , T , n , m , ans , min_dis , cnt;
vector<int> e[2000001];
void dfs(int now , int ed , int dis){
	if(now == ed){
		if(dis < min_dis){
			min_dis = dis;
			cnt = 1;
		}else if(dis == min_dis){
			cnt++;
		}
		return;
	}
	if(now > ed || dis > min_dis){
		return;
	}
	for(int v = 0;v < e[now].size();v++){
		dfs(e[now][v] , ed , dis + 1);
	}
}
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		ans = 0;
		cin>>n>>m;
		if(c <= 10){
			for(int i = 1;i <= n;i++){
				cin>>a[i];
				e[i].clear();
			}
			for(int i = 1;i < n;i++){
				for(int j = i + 1;j <= n;j++){
					if(a[j] - a[i] <= m){
						e[i].push_back(j);
					}else{
						continue;
					}
				}
			}
			for(int i = 1;i < n;i++){
				for(int j = i + 1;j <= n;j++){
					min_dis = n + 1;
					cnt = 0;
					dfs(i , j , 0);
					if(cnt == 2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}else{
			for(int i = 1;i <= n;i++){
				cin>>a[i];
			}
			int tt = a[2] - a[1];
			if(tt / m < 2){
				cout<<0<<'\n';
				continue;
			}else{
				cout<<n - (tt / m + 1)<<'\n';
			}
		}
	}
}
