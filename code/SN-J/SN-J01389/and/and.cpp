#include<bits/stdc++.h>
using namespace std;

struct cmpp
{
	long long e;
	long long q;
};

bool cmp(cmpp a,cmpp b)
{
	if(a.e>b.e)
	{
		return true;
	}
	else
	{
		if(a.e<b.e)
		{
			return false;
		}
		else
		{
			if(a.q>b.q)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

long long n=0,m=0;
cmpp a[200007];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		long long x=0;
		cin>>x;
		
		a[i].q=x;
		for(long long j=1;j>=0;j++)
		{
			if(x/2<1)
			{
				a[i].e++;
				break;
			}
			if(x%2==1)
			{
				a[i].e++;
				x=(x-1)/2;
			}
			else
			{
				x=x/2;
			}
		}
		
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1].q;
	for(long long i=2;i<=m;i++)
	{
		
		
			ans=ans&a[i].q;
		
		
		
		
	}
	cout<<ans;
	return 0;
}
