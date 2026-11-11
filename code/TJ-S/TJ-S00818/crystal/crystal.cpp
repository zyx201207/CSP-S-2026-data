#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long n,m,a[500005],ans,dp[500005],f[500005];

long long fs(long long l,long long j){
	if(dp[j]-dp[l]-(a[j]-a[l])*l<=m){
		return 1;
	}
	return 0;
}
int  main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	for(long long i=1;i<=n;i++){
		dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	long long l=0;
	for(long long i=1;i<=n;i++){
		if(fs(l,i)){
			f[i]=i-l;
		}
		else{
			while(fs(l,i)!=1){
				l++;
			}
		}
		ans=max(ans,f[i]);
	}
	
	cout<<ans;
	return 0;
}

