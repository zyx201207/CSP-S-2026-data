#include<stdio.h>
#include<algorithm>
#define MAXN 500005
using namespace std;
long long a[MAXN],q[MAXN];
int n;
long long m;
bool cmp(long long a,long long b)
{
	return a>b;
}
long long answ(long long k,long long newp)
{
	return (k-newp)*a[k]-(q[k-1]-q[newp-1]);
}
long long check(int l,int r)
{
	long long f=r;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		long long cnt=answ(f,mid);
		if(cnt>m)
			l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		q[i]=q[i-1]+a[i];
	long long ans=1;
	for(int i=2;i<=n;i++)
	{
		long long wa=check(1,i);
		ans=max(ans,i-wa+1);
	}
	printf("%lld",ans);
	return 0;
}
