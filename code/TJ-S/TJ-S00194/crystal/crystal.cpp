#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,ans=0;
long long a[500005]={0};
long long shuijing(long long x,long long y)
{
	int num=0;
	for(int i=x+1;i<=y;i++)
	{
		num+=(a[i]-a[i-1])*(i-x);
	}
	if(num<=m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000)
	{
		sort(a,a+n);
		for(long long i=0;i<n;i++)
		{
			int num=0;
			for(long long j=i+1;j<n;j++)
			{
				num+=(a[j]-a[j-1])*(j-i);
				if(num<=m)
				{
					ans=max(ans,j-i+1);
				}
				else
				{
					break; 
				} 
			}
		}
	}
	else
	{
		sort(a,a+n);
		long long k=a[1]-a[0];
		long long num=0;
		for(long long j=1;j<n;j++)
		{
			num+=k*j;
			if(num<=m)
			{
				ans=max(ans,j+1);
			}
			else
			{
				break; 
			} 
		}
	}
	cout<<ans;
	return 0;
}
