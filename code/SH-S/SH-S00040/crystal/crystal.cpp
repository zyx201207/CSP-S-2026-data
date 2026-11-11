#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],dp[500001][2],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[1][0]=1;
	for(int i=2;i<=n;i++){
		dp[i][1]=dp[i-1][1]+dp[i-1][0]*(a[i]-a[i-1]);
		dp[i][0]=dp[i-1][0]+1;
		while(dp[i][1]>m){
			dp[i][1]-=a[i]-a[i-dp[i][0]+1];
			dp[i][0]--;
		}
		ans=max(ans,dp[i][0]);
	}
	cout<<ans;
	return 0;
}
