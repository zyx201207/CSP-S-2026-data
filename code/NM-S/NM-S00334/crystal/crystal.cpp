#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500010],s[500010];
long long f(long long x){
	long long l=x,r=n+1;
	while(l+1<r){
		long long mid=(l+r)/2;
		if(a[mid]*(mid-x+1)-(s[mid]-s[x-1])<=m){
			l=mid;
		}else{
			r=mid;
		}
	}
	return l-x+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		ans=max(ans,f(i));
	}
	printf("%lld",ans);
	return 0;
}
