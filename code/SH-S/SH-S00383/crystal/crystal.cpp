#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
long long c[1000005];
long long n,m,cst;
long long bs(long long lt,long long rt,long long rowsum,long long bl)
{
	while(lt<=rt)
	{
		long long mid=(lt+rt)/2;
		//printf("++%lld %lld %lld %lld %lld\n",mid,b[n-1]-b[mid-1]+rowsum-(a[n]-a[mid])*(bl-1),b[n-1]-b[mid-1],rowsum,(a[n]-a[mid])*(bl-1));
		if(b[n-1]-b[mid-1]+rowsum-(a[n]-a[mid])*(bl-1)>=cst-m)
			lt=mid+1;
		else
			rt=mid-1;
	}
//	printf("//%lld\n",rt);
	return rt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++)
		b[i]=b[i-1]+(a[i+1]-a[i])*i;
	for(long long i=n;i>=1;i--)
	{
		cst+=a[n]-a[i];
	}
	long long sum=0,ans=0;
	for(long long i=1;i<=n;i++)
	{
	//	printf("**%lld %lld\n",a[i],b[i]);
		long long j=bs(i,n,sum,i);
		ans=max(ans,j-i+1);
		sum+=a[n]-a[i-1];
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
