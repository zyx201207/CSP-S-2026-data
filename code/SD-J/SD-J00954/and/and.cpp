#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int dp[2010][2010],a[2010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2000){
		//memset(dp,-0x3f,sizeof dp);
		for(int i=1;i<=n;i++)
			dp[i][1]=max(dp[i-1][1],a[i]);
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++)
				dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
		}
		cout<<dp[n][m];
	}
	
	else{
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=2;i<=m;i++)
			ans&=a[i];
		cout<<ans;
	}
	
	return 0;
}


