#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=a[n],cnt=m;
	vector<vector<long long> > dp(n+1,vector<long long>(m+1,0));
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==j&&i==1) continue;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
