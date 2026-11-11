#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	dp[1]=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}for(int i=2;i<=n;i++){
		if(m>=a[i]*(i-1)-sum[i-1]){
			dp[i]=i;
		}else{
			int l=1,r=i-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			dp[i]=i-l+1;
		}
	}long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}cout<<ans;
	return 0;
}