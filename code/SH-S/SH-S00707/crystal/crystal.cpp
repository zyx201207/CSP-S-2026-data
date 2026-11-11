#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n;
long long m,a[N];
long long dp[N][N][5];
long long ans=-1e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i][i][1]=1;
		dp[i][i][2]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((j-i)*(a[j]-a[j-1])+dp[i][j-1][2]<=m){
				dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][1]+1);
				dp[i][j][2]=max(dp[i][j][2],dp[i][j-1][2]+(j-i)*(a[j]-a[j-1]));
			}
			else{
				dp[i][j][1]=max(dp[i][j][1],dp[i][j-1][1]);
				dp[i][j][2]=m+1;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,dp[i][j][1]);
		}
	}
	cout<<ans;
	return 0;
}
