#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	for(int i=1;i<=n;i++)scanf("%lld",&dp[i]);
 	sort(dp+1,dp+1+n);
 	int minn=dp[1];
 	long long ans=0;
 	for(int i=2;i<=n;i++){
 		if(dp[i]!=minn){
 			ans+=(i-1)*(dp[i]-minn);
 			minn=dp[i];
 			
		}
		if(ans>m){
			cout<<i-1;
			return 0;
		}
	 }
	 cout<<n;
	 
	return 0;
} 
