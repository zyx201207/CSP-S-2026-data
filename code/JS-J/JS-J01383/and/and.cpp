#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int s[N],dp[N][N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) dp[i][1]=max(dp[i-1][1],s[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=2;k<=m;k++){
				dp[i][k]=max(dp[i-1][k-1]&s[j],dp[i-1][k]);
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i][m]);
	cout<<ans;
	return 0;
}
