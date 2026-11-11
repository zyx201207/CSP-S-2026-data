#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int a[1005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[1][i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
			for(int k=i-1;k<j;k++){
				dp[i][j]=max(dp[i][j],a[j]&dp[i-1][k]);
			}
		}
	}
	cout<<dp[m][n];
	return 0;
}
