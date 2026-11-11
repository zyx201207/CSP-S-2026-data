#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int c, t, n;
long long d;
long long x[N];
int dp[N][N];
int cnt[N][N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++){
			cin >> x[i];
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				for(int k = 1; k <= n; k ++){
					dp[j][k] = 1e9;
					cnt[j][k] = 0;
				}
			}
			for(int j = i; j <= n; j ++)dp[j][j] = 0, cnt[j][j] = 1;
			for(int j = i; j <= n; j ++){
				for(int k = j - 1; k >= i; k --){
					if(1ll * x[j] - x[k] <= d){
						if(dp[i][j] > dp[i][k] + 1){
							dp[i][j] = dp[i][k] + 1;
							cnt[i][j] = cnt[i][k];
						}
						else if(dp[i][j] == dp[i][k] + 1)cnt[i][j] += cnt[i][k];
					}
				}
				if(cnt[i][j] == 2)ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
