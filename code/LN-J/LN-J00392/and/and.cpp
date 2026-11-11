#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long dp[2005][20005];
long long qy[200005];
long long ma[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) qy[i] = a[i];
		else qy[i] = qy[i-1] & a[i];
		if(a[i]>ma[i-1]) ma[i] = a[i];
		else ma[i] = ma[i-1];
	}
	for(int i=1;i<=m;i++){
		dp[i][i] = qy[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=n;j++){
			if(i==1)dp[i][j] = ma[j];
			dp[i][j] = max(max(dp[i][j-1],dp[i-1][j-1]&a[j]),dp[i][j]);
		}
	}
	cout<<dp[m][n];
	return 0;
}
