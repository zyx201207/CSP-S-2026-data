#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,zz=1;
	cin>>n>>m;
	long long a[n+5],dp[n+5][m+5];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)cin>>a[i];
	dp[0][1]=a[0];
	for(int i=1;i<=m;i++)for(int ii=1;ii<n;ii++)dp[ii][i]=(long long)max((long long)dp[ii-1][i],(long long)dp[ii][i-1]&(long long)a[ii-1]);
	for(int i=0;i<=m;i++){
		for(int ii=0;ii<n;ii++)cout<<dp[ii][i]<<" ";
		cout<<endl;	
	}
	cout<<dp[n-1][m];
	return 0;
}
