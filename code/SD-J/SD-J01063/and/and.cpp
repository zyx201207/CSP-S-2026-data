#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m,a[200010],ans,dp[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0] = LONG_MAX;
	for(LL i=1;i<=n;i++){
		for(LL j=m;j>=1;j--){
			dp[j] = max(dp[j],dp[j-1]&a[i]);
		}	
	}
	cout<<dp[m];
	return 0;
}

