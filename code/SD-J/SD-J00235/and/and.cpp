#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+10;
int a[N];
int dp[N][N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
		dp[i][1]=maxx;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			cout<<dp[i][j]<<endl;
			if(j+1<=m){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
