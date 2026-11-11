#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2000100,inf = 1e18;
ll mp[maxn],dp[5050][5050],f[5050][5050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll taskid,T;
	cin>>taskid>>T;
	ll n,d,i,j,k,len,ans;
	while(T--){
		cin>>n>>d;
		ans = 0;
		for(i = 1;i <= n;i++) cin>>mp[i];
		for(i = 1;i <= n;i++){
			for(j = i + 1;j <= n;j++){
				if(abs(mp[i] - mp[j]) <= d){
					dp[i][j] = 1;
					f[i][j] = 1;
				}else{
					dp[i][j] = inf;
					f[i][j] = 0;
				}
				
			}
		}
		for(k = 1;k <= n;k++){
			for(i = 1;i <= n;i++){
				for(j = i + 1;j <= n;j++){
					if(dp[i][k] + dp[k][j] < dp[i][j]){
						dp[i][j] = dp[i][k] + dp[k][j];
						f[i][j] = f[i][k] * f[k][j];
					}else if(dp[i][k] + dp[k][j] == dp[i][j]){
						f[i][j] += f[i][k] * f[k][j];
					}
				}
			}
		}
		for(i = 1;i <= n;i++){
			for(j = 1;j <= n;j++){
				if(f[i][j] == 2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
