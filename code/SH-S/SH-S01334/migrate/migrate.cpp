#include<bits/stdc++.h>
#define int long long
using namespace std;
int c , t , n , d;
int x[2000010];
struct node{
	int len , cnt;
}dp[6010][6010];
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++)cin >> x[i];
		for(int i = 1 ; i <= n ; i++){
			dp[i][i] = {1 , 1};
		}
		int ans = 0;
		for(int i = 2 ; i <= n ; i++){
			for(int j = 1 ; j + i - 1 <= n ; j++){
				int r = j + i - 1;
				for(int k = j ; k < r ; k++){
					int flag = 0;
					if(k - 1 >= j){
						if(x[k] - x[k - 1] <= d)flag = 1;
					}
					if(k + 2 <= r){
						if(x[k + 1] - x[k] <= d)flag = 1;
					}
					if(k + 2 <= r && k - 1 >= j){
						if(x[k + 1] - x[k - 1] <= d)flag = 2;
					}
					if(dp[j][r].len == dp[j][k].len + dp[k + 1][r].len - flag)dp[j][r].cnt++;
					else if(dp[j][r].len < dp[j][k].len + dp[k + 1][r].len - flag)dp[j][r].cnt = 1LL , dp[j][r].cnt = dp[j][k].cnt + dp[k + 1][r].cnt - flag;
				}
				if(dp[j][r].cnt >= 2)ans++;
			}
		}
		cout << ans << '\n';
		memset(dp , 0 , sizeof dp);
	}
	return 0;
}
