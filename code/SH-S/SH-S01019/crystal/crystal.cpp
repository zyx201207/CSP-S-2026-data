#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k,a[500005],sum[500005];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(sum[i]-sum[i-x])<=k)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d",ans);
 } 
