#include <iostream>
#include <cmath>

using namespace std;

long long c, t, n, d, a[2000005], ans;
pair<long long, long long> dp[10005][10005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++){
			dp[i][1] = {1, 0};
			for(int j = 2;j <= n;j++){
				dp[i][j] = {0, 4e18};
			}
		}
		for(int j = 2;j <= n;j++){
			for(int i = 1;i <= n - j + 1;i++){
				if(abs(a[i + j - 1] - a[i]) <= d){
					dp[i][j] = {1, 1};
				}
				for(int k = 2;k < j;k++){
					pair<long long, long long> dp1 = dp[i][k], dp2 = dp[i + k - 1][j - k + 1];
					long long abab = dp1.second + dp2.second;
					if(dp[i][j].second > abab){
						dp[i][j] = {dp1.first * dp2.first, abab};
					}else if(dp[i][j].second == abab){
						dp[i][j].first += (dp1.first * dp2.first);
					}
				}
				if(dp[i][j].first == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	} 
}
/*
卡住了，继续写游记。 
上午的J简直一坨，T2正解都没想出来。
教我拼好分的同学坐在我后面，她T3只拼出来55，但我最高75 ^v^
忽然不想写游记了
那就byebye 
*/

