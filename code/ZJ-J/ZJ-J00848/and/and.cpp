#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],dp[2009][2009],ans,mi=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][1]=a[i];
		if(a[mi]>a[i])mi=i;
	}
	if(m==n-1){
		ans=a[1];
		for(int i=1;i<=n;i++){
			if(i!=mi){
				ans&=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			for(int x=1;x<i;x++){
				dp[i][j]=max(dp[i][j],dp[x][j-1]&a[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
