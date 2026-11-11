#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],qh[500009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		qh[i]=qh[i-1]+a[i];
	}
	long long l=0,r=n+1;
	while(l<r-1){
		long long mid=(l+r)/2,xans=0,minn=1e18;
		for(long long i=mid;i<=n;i++){
			xans=(mid-1)*a[i]-(qh[i-1]-qh[i-mid]);
			minn=min(minn,xans);
		}
		if(minn<=m)l=mid;
		else r=mid;
	}
	printf("%lld",l);
	return 0;
}
