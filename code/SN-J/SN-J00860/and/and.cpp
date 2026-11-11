#include<bits/stdc++.h>
using namespace std;
#define int long long
int v[200005];
int w[200005];
int dp[2005][2005];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		w[i]=1;
	}
	dp[0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i][j],(dp[i][j]-w[i])&v[i]);
			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[m][n];
	return 0;
}


