#include<bits/stdc++.h>
using namespace std;
const int M=8200;
int a[M];
int presum[M],backsum[M];
int dp[M][M];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n-1){
		presum[2]=a[1];
		for(int i=3;i<=n;i++){
			presum[i]=presum[i-1]&a[i];
		}
		backsum[n-1]=a[n];
		for(int i=n-2;i>=1;i--){
			backsum[i]=backsum[i+1]&a[i];
		}
		int ans=max(presum[n],backsum[1]);
		for(int i=2;i<m;i++){
			ans=max(ans,presum[i]&backsum[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1]&a[i],dp[i][j]));
		}
	}
	cout<<dp[n][m]<<'\n';
	
	return 0;
}
