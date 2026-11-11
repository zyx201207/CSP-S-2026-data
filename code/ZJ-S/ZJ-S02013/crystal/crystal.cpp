#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[5000055];
int sum[500055];
int dp[500055];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	while(l<=r && l<=n && r<=n){
		if(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m){
			dp[r]=r-l+1;
		}
		else{
			while(a[r]*(r-l+1)-sum[r]+sum[l-1]>m){
				l++;
			}
			dp[r]=r-l+1;
		}
		r++;
	//	cout<<dp[r-1]<<" ";
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
//		cout<<dp[i]<<"\n";
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}