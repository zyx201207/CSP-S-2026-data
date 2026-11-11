#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],dp[5001][5001],zd[200001],yd[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	if(m==n-1){
		int ans=0;
		zd[1]=a[1];
		for(int i=2;i<=n;i++){
			zd[i]=zd[i-1]&a[i];
		}
		yd[n]=a[n];
		for(int i=n-1;i>=1;i--){
			yd[i]=yd[i+1]&a[i];
		}
		ans=max(yd[2],zd[n-1]);
		for(int i=2;i<n;i++){
		int x=yd[i+1]&zd[i-1];
			ans=max(ans,x);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n>2000){
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=max(a[i],dp[i-1][1]);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i;j++){
			dp[i][j]=max(dp[i-1][j-1]&a[i],dp[i-1][j]);
			
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}

