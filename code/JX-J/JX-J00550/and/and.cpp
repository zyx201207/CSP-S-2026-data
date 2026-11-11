#include<bits/stdc++.h>
using namespace std;
int n,k,dp[2010][2010],a[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
    if(n>2000){
		sort(a+1,a+n+1);
		int ans=a[1];
		for(int i=2;i<=k;i++){
			ans=ans&a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(k==2){
		int ans=0;
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++)
		        ans=max(ans,a[i]&a[j]);
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=min(i,k);j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][k]<<'\n';
    return 0;
}
