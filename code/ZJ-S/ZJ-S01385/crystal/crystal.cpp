#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,sum=0,a[N],b[N];
bool check(long long now,long long i){
	long long need=(i-now+1)*a[i];
	long long real=b[i]-b[now-1];
	return (real+m>=need);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,ans=i;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(check(mid,i))r=mid-1,ans=mid;
			else l=mid+1;
		}
		sum=max(sum,i-ans+1);
	}
	printf("%lld",sum);
	return 0;
}
