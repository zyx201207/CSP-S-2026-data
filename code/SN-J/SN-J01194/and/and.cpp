#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,m,a[N],dp[N][N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=a[i];
		for(int j=2;j<=i-1;j++){
			dp[i][j]=max(dp[i][j-1],(dp[i][j-1]&a[i]));
		}
	} 
	cout<<dp[n][m];
	 
	return 0;
}
