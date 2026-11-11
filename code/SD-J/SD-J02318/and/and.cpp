#include <bits/stdc++.h>
using namespace std;
const int N=2010;
int a[N],n,m,cnt,dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	dp[1][1]=a[1];
	if(m==n){
		int ans=a[1];
		for (int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int maxn=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
		}
		cout<<maxn;
		return 0;
	}
	for (int i=2;i<=n;i++) dp[i][1]=max(dp[i-1][1],a[i]);
	for (int i=2;i<=m;i++) dp[1][i]=dp[1][i-1];
	for (int i=2;i<=n;i++){
		for (int j=2;j<=m;j++) dp[i][j]=max(dp[i][j],dp[i][j-1]&a[i]); 
	}
	cout<<dp[n][m];
	return 0;
}
