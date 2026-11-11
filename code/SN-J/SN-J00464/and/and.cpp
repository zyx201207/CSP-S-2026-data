#include<bits/stdc++.h>
using namespace std;
#define PID "and"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
const long long N=2e5+10,M=1e3+10;
long long n,m,dp[M][N],ans;
int main(){
	FI;FO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>dp[1][i];
//		cout<<i<<":"<<dp[1][i]<<"\n";
	}
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
//			cout<<i<<"-"<<j<<":";
			for(int k=i-1;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[1][j]&dp[i-1][k]);
//				cout<<k<<":"<<dp[i-1][k]<<"/";
			}
			if(i==m){
				ans=max(ans,dp[i][j]);
			}
//			cout<<dp[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<ans;
	return 0;
}
