#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	long long dp[n+10][m+10];
	long long g[n+10];
	long long a[n+10];
	memset(dp,-0x3f,sizeof(dp));
	for(int i = 0;i<n;i++){
		cin >>g[i];
	}
	sort(g,g+n);
	for(int i = 0,j = n-1;i<n;i++,j--){
		a[i] = g[j];
	}
	dp[0][0] = a[0];
	for(int i = 1;i<m;i++){
		dp[i][i] = dp[i-1][i-1]&a[i];
	}
	for(int i = 1;i<n;i++){
		dp[i][1] = max(a[i],dp[i-1][1]);
	}
	for(int k = 2;k<=m;k++){
		for(int i = k;i<n;i++){
			dp[i][k] = max(dp[i-1][k],dp[i][k-1]&a[i]);
		}
	}
	cout <<dp[n-1][m-1];
	return 0;
}
