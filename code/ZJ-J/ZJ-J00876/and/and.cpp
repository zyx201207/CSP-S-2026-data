#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long dp[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(dp[i][1]==0) dp[i][1]=a[i];
		for(int j=1;j<=min(i,m);j++){
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);	
		}
	}
	cout<<dp[n][m];
	return 0;
}

