#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1,a[500055],sum[500055],dp[500055][3];//dp1answer  dp2len
bool check(int l,int r,int x){
	return m>=x*(r-l+1)-(sum[r]-sum[l-1])?1:0;
}
int bs(int ll,int rr){
	int l=ll,r=rr,len=rr-ll+1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid,rr/**/,a[rr+1])){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	dp[1][1]=1;dp[1][2]=0;
	for(int i=2;i<=n;i++){
		int t=bs(i-1-dp[i-1][2],i-1);
		dp[i][2]=i-t;
		dp[i][1]=dp[i][2]+1;
		ans=max(ans,dp[i][1]);
	}
	cout<<ans;	
	return 0;
}