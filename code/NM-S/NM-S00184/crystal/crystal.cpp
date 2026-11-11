#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long k[600000];
long long dp[600000];
long long shiyong[600000];
long long HHH;
long long check(long long h,long long p,long long yuanben){
	if((h-yuanben)*(k[h]-k[h-1])>p||h>n){
		HHH=p;
		return h-1;
	}long long j=(h-yuanben)*(k[h]-k[h-1]);
	check(h+1,p-j,yuanben);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		
	}sort(k+1,k+n+1);
	long long ans=1;
	
	for(int i=1;i<=n;i++){
		long long sum;
		if(dp[i-1]==n||i==n){
			break;
		}
		if(dp[i-1]<=i){
			sum=check(i+1,m,i);
			shiyong[i]=HHH;
			dp[i]=sum;
		}else{
			long long lin=shiyong[i-1]+k[dp[i-1]]-k[i-1];
			sum=check(dp[i-1]+1,lin,i);
			shiyong[i]=HHH;
			dp[i]=sum;
		}
	}for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]-i+1);
	}cout<<ans;
	return 0;
} 
