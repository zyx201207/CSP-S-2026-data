#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxn1,maxn2,maxn3,maxn4,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn1=a[i];
		}
	}
	if(m==1)
	{
		cout<<maxn1;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]&a[j]>maxn2)
				{
					maxn2=i&j;
				}
			}
		}
		cout<<maxn2;
	}
	else if(m==n)
	{
		maxn3=a[1];
		for(int i=2;i<=n;i++)
		{
			maxn3=maxn3&a[i];
		}
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			sum=a[1];
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				else
				{
					sum=sum&a[j];
				}
			}
			if(maxn4<sum)
				maxn4=sum;
		}
		cout<<maxn4;
	}
	return 0;
}
