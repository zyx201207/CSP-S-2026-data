#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long dp[n+1][m+1];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			dp[i][j]=0;
		}
	} 
	long long a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1][1]=a[1];
	for(long long i=2;i<=n;i++){
		for(long long j=0;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
} 
