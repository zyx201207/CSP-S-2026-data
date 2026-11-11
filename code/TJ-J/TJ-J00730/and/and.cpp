#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long dp[200005];
long long ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		dp[1]=a[k];
		for(int i=2;i<=m;i++){
			dp[m]=0;
			for(int j=1;j<=n;j++){
				if(j==k)continue;
				dp[i]=max(dp[i],dp[i-1]&a[j]);
			}
		}
		ans=max(ans,dp[m]);
	}
	cout<<ans;
	return 0;
}
