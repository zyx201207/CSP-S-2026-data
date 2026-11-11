#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long dp[20100][5100];
long long ans=0;
long long maxdp=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==1){
				dp[i][j]=max(dp[i-1][j],a[i]);
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		maxdp=max(maxdp,dp[i][m]);
	}
	cout<<maxdp;
	return 0;
}