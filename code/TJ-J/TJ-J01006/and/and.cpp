#include<bits/stdc++.h>
using namespace std;
int dp[200009]={0},a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	dp[1]=a[1];
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=m;j++){
			dp[j]=max(dp[j],dp[j-i]&a[i]);
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
