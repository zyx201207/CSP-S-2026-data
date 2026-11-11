#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	if(m==n)
	{
		scanf("%lld",&a[1]);
		long long ans=a[1];
		for(int i=2;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			ans=ans&a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==1)
	{
		long long mx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			mx=max(mx,a[i]);
		}
		printf("%lld",mx);
		return 0;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++)
	{
		ans=ans&a[i];
	}
	printf("%lld",ans); 
	return 0;
}

