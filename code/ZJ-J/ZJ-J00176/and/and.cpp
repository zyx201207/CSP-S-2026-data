#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	int n,m;cin>>n>>m;
	//long long dp[n+1][m+1];
	//memset(dp,0,sizeof(dp));
	long long a[N];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++){
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&&a[i])；
		}
	}
	cout<<dp[n][m];*/
	//cout<<3&&20;
	//cout<<n<<m;
	sort(a+1,a+1+n);
	cout<<a[1];
	return 0;
}