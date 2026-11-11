#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		if(i)cin>>a[i];
		dp[i][0]=pow(2,31)-1;
	}
	if(m==n){
		int ans=pow(2,31)-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n>2000){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	cout<<dp[n][m];
	return 0;
}
