#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[500005],sum,ans[500005],n,m;
bool f(long long x){
	for(int i=x;i<=n;i++){
		//cout<<i<<" "<<x<<" "<<a[i]*x<<" "<<ans[i]-ans[i-x]<<endl;
		if(a[i]*x-(ans[i]-ans[i-x])<=m)return 1;
	}
	return 0;
}
signed main(){
  	freopen("crystal.in","r",stdin);
   	freopen("crystal.out","w",stdout);
   	scanf("%lld %lld",&n,&m);
   	for(int i=1;i<=n;i++){
   		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(f(mid)){
			sum=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",sum);
	return 0;
}  
