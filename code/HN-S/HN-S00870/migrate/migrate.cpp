#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,arr[20005],cnt[505][505],ans,dp[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=0;
				if(i==j || abs(arr[i]-arr[j])>d){
					dp[i][j]=1e17;
					continue;
				}
				dp[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i==j){
					continue;
				}
				for(int k=i+1;k<=n;k++){
					if(i==k || j==k){
						continue;
					}
					if(dp[j][k]>dp[j][i]+dp[i][k]){
						dp[j][k]=dp[j][i]+dp[i][k];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i==j){
					continue;
				}
				for(int k=i+1;k<=n;k++){
					if(i==k || j==k){
						continue;
					}
					if(dp[j][k]==dp[j][i]+dp[i][k]){
						cnt[j][k]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

