#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010][2];
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1][0]=0;
	dp[1][1]=a[1];
	dp[0][1]=dp[0][0]=max(dp[0][1],a[1]);
	for(int i=2;i<=n;i++){
		dp[0][1]=dp[0][0]=max(dp[0][1],a[i]);
		for(int j=m;j>=1;j--){
			dp[j][0]=max(dp[j][0],dp[j][1]);
			if(j>0)dp[j][1]=max(dp[j-1][0]&a[i],dp[j-1][1]&a[i]);
		}
	}
	cout<<max(dp[m][0],dp[m][1]);
	return 0;
}
