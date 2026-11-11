//SN-S00226
//long long !
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long sum[500010];
bool check(int x){//x个水晶能不能满足 
	for(int i=1;i<=n-x+1;i++){
		//[i,i+x-1]
		long long t=sum[i+x-1]-sum[i-1];
		t=a[i+x-1]*x-t;
		if(t<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long l=1,r=n;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
