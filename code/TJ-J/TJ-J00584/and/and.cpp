#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int> > dp(n+5,vector<int>(m+5,0));
	//dp[0][0]=0; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m,i);j++){
			if(j==1)dp[i][j]=a[i];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			//cout<<dp[i][j]<<" ";
		}
	}cout<<dp[n][m];
	return 0;
}
