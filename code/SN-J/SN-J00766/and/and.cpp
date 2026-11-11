//姓名：霍梓颐 考号：SN-J00766 学校：西北大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int a[100005];
int n,m; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][1]=max(dp[i-1][0],a[i]);
	}
	for(int j=1;j<=m;j++){
		dp[1][j]=a[1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
