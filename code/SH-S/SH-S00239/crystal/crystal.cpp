#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int maxn=5e5+5;
int n;
long long m,a[maxn],b[maxn],sum,h,H,ans=1,ansnow,MAX=-1000000000001;
bool fa=1,fb=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
		MAX=max(MAX,a[i]);
		if(fa&&a[i]!=i)fa=0;
		if(i>=3&&fb&&a[i]-a[i-1]!=a[i-1]-a[i-2])fb=0;
	}
	if(fa)
	{
		long long x=1;
		while(m-x>=0&&x<n)
		{
			m-=x;
			x+=1;
		}
		printf("%lld",x);
		return 0;
	}
	if(fb)
	{
		h=a[2]-a[1];
		long long x=1;
		while(m-x*h>=0&&x<n)
		{
			m=m-x*h;
			x+=1;
		}
		printf("%lld",x);
		return 0;
	}
	H=MAX*n-sum;
	if(H<=m)printf("%d",n);
	else 
	{
		sort(a+1,a+1+n);
		for(int i=1;i<=n-1;i++)
		{
			b[i]=a[i+1]-a[i];
		}
		for(int i=1;i<=n-ans;i++)
		{
			ansnow=1;
			while(i+ansnow<=n&&m-ansnow*b[i+ansnow-1]>=0)
			{
				m-=ansnow*b[i+ansnow-1];
				ansnow++;
			}
			ans=max(ans,ansnow);
		}
		printf("%lld",ans);
	}
	
	
	return 0;
}
