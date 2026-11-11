#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500195],f1,f2,b[250];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=1)
		{
			f1=1;
		}
		if(a[i]-a[i-1]!=a[2]-a[1])
		{
			f2=1;
		}
	}
	if(f1==0)
	{
		long long l=1,ans=1;
		while(m>0)
		{
			if(m-l>=0)
			{
				m-=l;
				l++;
				ans++;
			}
			else
			{
				m=0;
			}
		}
		if(ans>n)
		{
			ans=n;
		}
		cout<<ans;
	}
	else if(f2==0)
	{
		long long l=a[2]-a[1],ans=1;
		while(m>0)
		{
			if(m-l>=0)
			{
				m-=l;
				l+=a[2]-a[1];
				ans++;
			}
			else
			{
				m=0;
			}
		}
		if(ans>n)
		{
			ans=n;
		}
		cout<<ans;
	}
	else if(n<=5000)
	{
		long long ans=-1e12+100;
		for(long long i=1;i<=n;i++)
		{
			long long sum=m,l=1;
			for(long j=i-1;j>=1;j--)
			{
				if(sum-(a[i]-a[j])>=0)
				{
					l++;
					sum-=(a[i]-a[j]);
				}
				else
				{
					j=0;
				}
			}
			ans=max(ans,l);
		}
		cout<<ans;
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			b[a[i]+101]++;
		}
		long long ans=-1e12+100;
		for(long long i=1;i<=201;i++)
		{
			if(b[i]!=0)
			{
				long long sum=m,l=b[i];
				for(long long j=i-1;j>=1;j--)
				{
					if(b[j]!=0)
					{
						if(sum-((i-j)*b[j])>=0)
						{
							sum-=((i-j)*b[j]);
							l+=b[j];
						}
						else
						{
							l+=sum/(i-j);
							j=0;
						}
					}
				}
				ans=max(ans,l);
			}
		}
		cout<<ans;
	}
	return 0;
} 
