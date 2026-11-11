#include<bits/stdc++.h>
int dp[2005][2005];
int a[200005];
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;int maxx=-2e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=-2e9;
		dp[i][1]=a[i];
	}
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(i==1&&j==1){
				continue;
			}
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			maxx=max(maxx,dp[i][j]);
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<maxx;
	return 0;
} 
