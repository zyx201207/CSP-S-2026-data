#include <bits/stdc++.h>
using namespace std;
int a[200010],dp[1010][1010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) dp[0][i]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[i][j]=dp[i-1][j];
			dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
}