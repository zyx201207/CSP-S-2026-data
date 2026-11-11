#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[1]=max(dp[1],a[i]);
		dp[i]=dp[i-1]&a[i];
		for(int j=i-1;j>=i-m&&j>=1;j--){
			dp[i]=max(dp[i],dp[j]&dp[i-j-1]&a[i]);
			dp[i]=max(dp[i],dp[j-1]&dp[i-j]&a[i]);
		}
	}
	cout<<dp[n];
	return 0;
}
