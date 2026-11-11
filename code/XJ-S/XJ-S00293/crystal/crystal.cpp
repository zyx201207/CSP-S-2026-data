#include<iostream>
using namespace std;
long long a[500005];
long long maxx=0,mt;
long long n,m;
void dfs(long long x)
{
	if(x>n||mt==0)
	{
		if(mt==0)
		{
			for(long long i=1;i<=n;i++)
			{
				long long sum=0;
				for(long long j=1;j<=n;j++)
				{
					if(a[i]==a[j])
					{
						 sum++;
					}
				}
				if(sum>maxx)
				{
					maxx=sum;
				}
			}
		}
		return ;
	}
	for(long long i=1;i<=mt;i++)
	{
		a[x]+=i;
		mt-=i;
		dfs(x+1);
		a[x]-=i;
		mt+=i;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,j,num=0,p;
	cin>>n>>m;
	mt=m;
	p=m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			num++;
		}
	}
	if(num==n)
	{
		for(i=1;i<=m;i++)
		{
			p-=i;
			if(p<0)
			{
				cout<<i;
				return 0;
			}
			if(p==0)
			{
				cout<<i+1;
				return 0;
			}
			if(i==n-1)
			{
				cout<<n-1;
				return 0;
			}
		}
	}
	dfs(1);
	cout<<maxx;
	return 0;
}
