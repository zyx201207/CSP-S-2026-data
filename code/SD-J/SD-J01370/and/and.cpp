#include <bits/stdc++.h>
using namespace std;
#define N 200005
long long n,m,x=1;
long long ans=0,maxn=0;
long long a[N];
int cmp(int p,int q)
{
	return p>q; 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			x*=2;
		}
		for(long long i=1;i<=x;i++)
		{
			long long y=i,cnt=0,num,cnta=1;
			while(y)
			{
				if(y&1)
				{
					cnt++;
					if(cnt==1)
					{
						num=a[cnta];
					}
					else
					{
						num=num&a[cnta];
					}
				}
				y>>=1;
				cnta++;
			}
			if(cnt==m)
			{
				ans=max(ans,num);
			}
		}
	}
	else if(m==1)
	{
		ans=maxn;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	else if(m==n-1)
	{
		int j=1;
		while(j<=n)
		{
			long long sum=0,f=0;
			for(int i=1;i<=n;i++)
			{
				if(i==j)
				{
					continue;
				}
				if(f==0)
				{
					sum=a[i];
					f=1;
				}
				else
				{
					sum=sum&a[i];
				}
			}
			ans=max(ans,sum);
			j++;
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		ans=a[m];
	}
	printf("%lld\n",ans);
	return 0;
}
