#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010] , n , d;
int dis[310][310] , num[310][310];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
//	c = 11;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(c <= 6){
			memset(dis , 0x3f , sizeof dis);
			memset(num , 0 , sizeof num);
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j) dis[i][j] = 0 , num[i][j] = 1;
					else{
						if(abs(a[i] - a[j]) <= d) dis[i][j] = 1 , num[i][j] = 1;
					}
				}
			}
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j) continue;
					for(int k = 1; k <= n; k++){
						if(i == k || j == k) continue;
						if(dis[j][i] + dis[i][k] < dis[j][k]) dis[j][k] = dis[j][i] + dis[i][k] , num[j][k] = num[j][i] * num[i][k];
						else if(dis[j][i] + dis[i][k] == dis[j][k]) num[j][k] += num[j][i] * num[i][k];
					}
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					if(num[i][j] == 2){
						ans++;
	//					cout << dis[i][j] << " ";
					}
				}
			}
			cout << ans << "\n";
		}else if(c == 11 || c == 12){
			if(d <= a[2] - a[1] || n - 2 * d / (a[2] - a[1]) + 1 < 0) cout << "0\n";
			else cout << n - 2 * d / (a[2] - a[1]) + 1 << "\n";
		}
	}
	return 0;
}