#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long a[1000005],n,m;
long long dp[5005][5005];
void dfs(long long u,long long k){
	dp[u][k]++;
	for(int i = 2;i<=n;i++){
		if(a[i]>a[u] && a[i]-a[u]<=m){
			dfs(i,k+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		long long ans = 0;
		for(int i = 1;i<=n;i++){
			dfs(i,0);
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					if(dp[j][k]<=0) continue;
					if(dp[j][k] == 2){
						ans++;
					}
					break;
				}
			}
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					dp[j][k] = 0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
