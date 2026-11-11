#include<bits/stdc++.h>
using namespace std;
int n,m,a[(int) 2e5+10];
vector<vector<int> > dp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp.resize(n+10);
	for(int i=1;i<=n;i++){
		dp[i].resize(m+10);
	}
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][1]=max(a[i],dp[i-1][1]);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1) dp[i][1]=max(a[i],dp[i-1][1]);
			else{
				dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
