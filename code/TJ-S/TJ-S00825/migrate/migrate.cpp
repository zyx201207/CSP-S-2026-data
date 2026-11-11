#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long dp[5005][5005];
inline void solve(){
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(abs(a[j]-a[k])<=m){
					dp[i][j]=min(dp[i][j],dp[i][k]+1);
				}else{
					break;
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			int ans=0;
			for(int k=j-1;k>=i;k--){
				if(dp[i][k]+1==dp[i][j]){
					ans++;
				}
			}
			if(ans==2){
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,t;
	cin>>C>>t;
	while(t--){
		solve();
	}
	return 0;
}
//zsy
