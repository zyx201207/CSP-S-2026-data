#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
bool check(long long s){
	long long k=m,cnt=0,pp=s;
	for(long long i=1;i<=s;i++){
		cnt+=a[pp]-a[i];
	}
	if(cnt<k)return 1;
	else{
		for(long long i=1;i<=n-s;i++){
			cnt-=a[pp]-a[i];
			cnt+=(s-1)*(a[pp+1]-a[pp]);
			pp++;
			if(cnt<k) return 1;
		}
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<r-1){
		long long mid;
		if((l+r)%2==0)mid=(l+r)/2;
		else mid=(l+r-1)/2;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}
