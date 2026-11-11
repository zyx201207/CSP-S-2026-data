#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int dp[5005][5005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=0x3f3f3f3f3f3f3f3f;
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==m&&i>m){
				dp[i][j]=max(dp[i-1][j-1],dp[i][j-1]&a[i]);
			}else{
				dp[i][j]=dp[i-1][j-1]&a[i];	
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}