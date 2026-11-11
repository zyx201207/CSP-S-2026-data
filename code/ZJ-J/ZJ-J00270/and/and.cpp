#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int ans=0,dp[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1][1]=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(a[i-1][j],);
		}
	}
	return 0;
}
