#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
int dp[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
