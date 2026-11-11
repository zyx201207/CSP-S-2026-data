#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int dp[500005];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int m,n;
	
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		//TODO
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
	dp[1]=0;
	for(int i = 2;i<=n;i++){
		dp[i] = dp[i-1]+(a[i]-a[i-1])*(i-1);
		if(dp[i]>m){
//			cout<<dp[i]<<"\n";
			cout<<i-1ll;
			return 0;
		}
	}
	if(dp[n]<=m)cout<<n;
	
	return 0;
}