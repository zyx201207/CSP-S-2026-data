#include<bits/stdc++.h>
using namespace std;
int n,m,a[200006],dp[2006][2006];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		dp[i][1]=a[i];
	}
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=m&&j<=i;j++) {
			for(int k=j-1;k<i;k++) {
				dp[i][j]=max(dp[k][j-1]&a[i],dp[i][j]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
