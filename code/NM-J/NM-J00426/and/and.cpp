#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		dp[i][0]=a[i];
		
	}
	for(int i=0;i<=m;++i){
		dp[0][i]=a[1];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i-1>=j){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}else{
				dp[i][j]=dp[i-1][j-1]&a[i];
			}
			
		}
	}
	cout<<dp[n][m];
	return 0;
}
