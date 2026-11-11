#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m;
long long a[N];
long long ans;
long long dp[N][N];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mx=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
		dp[i][1]=mx;
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=m;j++) {
			if (j==0) dp[i][j]=0;
			else if (j==1) ;
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	}
	for (int i=m;i<=n;i++) {
		ans=max(ans,dp[i][m]);
	}
	cout<<ans<<'\n';
	return 0;
}
//5 3
//31 3 1 15 7
