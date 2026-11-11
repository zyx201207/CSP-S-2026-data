#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;
long long a[200010],dp[10010][10010];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1][1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][1]=max(a[i],dp[i-1][1]);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i&&j<=m;j++){
			if(i==j){
				dp[i][j]=dp[i-1][j-1]&a[j];
			}
			else{
			
			long long b=dp[i-1][j-1]&a[i];
			dp[i][j]=max(dp[i-1][j],b);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
