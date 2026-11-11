/*
dp[i][j]=前i件物品选取j件可以取到的最大值
dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
初始化：dp[][]={1<<30-1} 
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int tmax=(1<<30)-1;
	cin>>n>>m;
	int a[n+5]; 
	int dp[n+1][m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=max(n,m);i++){
		dp[i][0]=tmax;
	}
	for(int i=1;i<=max(n,m);i++){
		dp[0][i]=tmax;
	}
	int chex=a[1];
	for(int j=1;j<=m;j++){
		for(int i=j;i<=n;i++){
			if(dp[i-1][j]==tmax){
				dp[i][j]=dp[i-1][j-1]&a[i];
//				cout<<dp[i][j]<<" ";
				continue;
			}else if(dp[i][j-1]==tmax){
				dp[i][j]=max(chex,a[i]);
				chex=max(chex,a[i]);
//				cout<<dp[i][j]<<" ";
				continue;
			}
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	cout<<dp[n][m];
	return 0;
} 
