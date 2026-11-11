#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],cha[500050],sum,ans,den;
bool f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f=false;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
		{
			den=a[i]-a[i-1];
		}
		if(i>2&&a[i]-a[i-1]!=den)
		{
			f=true;
		}
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
	}
	if(f)
	{
		for(long long i=1;i<=n-ans;i++)
		{
			sum=0;
			for(long long j=i+1;j<=n;j++)
			{
				sum+=cha[j]*(j-i);
				if(sum>m)
				{
					if(j-i>ans)
					{
						ans=j-i;
					}
					break;
				}
			}
		}
	}
	else if(!f)
	{
		for(long long i=2;i<=n;i++)
		{
			sum+=cha[i]*(i-1);
			if(sum>m)
			{
				ans=i-1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
