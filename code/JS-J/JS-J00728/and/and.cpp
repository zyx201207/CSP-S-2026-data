#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[3000];
long long dp[3003][3007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	//cout<<1;
	for(int i=1;i<=n;i++){ dp[i][1]=max(dp[i-1][1],a[i]);}
	
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			//cout<<i<<j<<endl;
			
			if(i<j) dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<" ";
			}
			cout<<endl;
			}*/
	cout<<dp[n][m];
	return 0;
}
