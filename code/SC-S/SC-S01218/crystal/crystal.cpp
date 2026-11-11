#include<bits/stdc++.h>
const long long N=5e5+5;
long long n,m,ans,sum,a[N];
long long check(long long k){
	long long sum=0;
	for(long long i=1;i<=k;i++)sum+=a[k]-a[i];
	ans=sum;
	// printf("%lld\n",sum);
	for(long long i=k+1;i<=n;i++){
		sum+=k*(a[i]-a[i-1])-(a[i]-a[i-k]);
		ans=std::min(ans,sum);
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	// printf("%lld\n",check(4429));
	long long l=1,r=n+1;
	while(l<r){
		long long mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l-1);
}