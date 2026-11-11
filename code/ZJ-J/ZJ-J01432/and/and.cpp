#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10005];
long long dp[10005][10005];
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i <= n+1;i++){
		dp[0][i] = 1073741823;
		dp[i][0] = 1073741823;
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		dp[i][i] = dp[i-1][i-1]&a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i && j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1] & a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
