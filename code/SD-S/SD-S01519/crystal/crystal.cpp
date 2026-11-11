#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,s[500005];
long long ef(long long x)
{
	long long l=0,r=x-1,mid,k=0;
	while(l<r)
	{
		mid=(l+r)>>1;
		k=(s[x]-mid*(a[x]-a[mid])-s[mid]);
		if(k<=m)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);

	for(int i=2;i<=n;i++)
	{
		s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];	
	}
	long long f=0;
	for(int i=1;i<=n;i++)
	{
		f=ef(i);
		if(f<i)
		{
			ans=max(ans,i-f);
		}
	}
	printf("%lld",ans);
	return 0;
} 
