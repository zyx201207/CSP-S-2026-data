#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000005];
int dp[2000005];
void solve(){
	int n;
	int d,ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		memset(dp,0,sizeof dp);
		for(int j = i + 1;j <= n;j++){
			if(a[j] - a[i] <= d) dp[j] = 1;
			else{
				for(int k = 1;k <= d;k++)
					if(a[j] - a[j - k] <= d)
						dp[j] += dp[j - k];
					else break;
			}
			if(dp[j] == 2) ans++;
		}
		//for(int j = 1;j <= n;j++) cout << dp[j] << ' ';
		//cout << endl;
	}	
	cout << ans << '\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
		solve();
	return 0;
}
