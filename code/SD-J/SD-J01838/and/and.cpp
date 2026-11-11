#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,a[2000005],m,dp[20005][20005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=max(a[i],dp[i-1][1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=dp[i][j-1]&a[i];
			for(int k=1;k<i;k++){
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
} 
