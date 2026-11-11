#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010][40],l,r,t[200010],ans=1,sum;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i]);
	}
	sort(t+1,t+n+1,cmp);
	l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			a[i][30-j+1]=(t[i]>>j)&1;
		}
	}
	for(int j=1;j<=31;j++)
	{
		if(r-l+1==m)
		{
			ans=t[l];
			for(int i=l+1;i<=r;i++)
			{
				ans=ans&t[i];
			}
			printf("%lld\n",ans);
			return 0;
		}
		sum=0;
		long long tl=0,tr=0;
		for(int i=l;i<=r;i++)
		{
			if(a[i][j])
			{
				sum++;
				if(!tl)tl=i;
				tr=i;
			}
		}
		if(sum>=m)
		{
			l=tl,r=tr;
		}
	}
	ans=t[l];
	for(int i=l+1;i<=l+m-1;i++)
	{
		ans=ans&t[i];
	}
	printf("%lld\n",ans);
	return 0;
}