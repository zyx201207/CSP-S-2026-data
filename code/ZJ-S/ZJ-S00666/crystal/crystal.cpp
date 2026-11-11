#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
long long check(int i){
	long long l=1,r=i-1,ans=0;
	while(l<=r){
		long long mid=l+r>>1;
		if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
			ans=max(ans,i-mid+1);
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long ans=0;
	for(long long i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	cout<<ans;
	
	return 0;
}