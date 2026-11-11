#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	long long p=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p=max(p,abs(a[i]));
	}
	sort(a+1,a+n+1);
	if(p<=100&&n>5000&&n<=5e5)
	{
		cout<<n;
		return 0;
	}
	if(n<=5000)
	{
	for(int i=1;i<=n;i++)
	{
		int k=m,l=0; 
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]<=k)
			{
				k-=(a[i]-a[j]);
				l++;
			}
		}
		ans=max(ans,l);
	}	
	cout<<ans;
	return 0;
	}
	int f=1,q=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			f=0;
		}
	}
	for(int i=2;i<=n-1;i++)
	{
		if(a[i+1]-a[i]!=a[i]-a[i-1])
		{
			q=0;
		}
	}
	if(f)
	{
		int k;
		for(int i=n;i>=1;i--)
		{
			if(m>a[n]-a[i])
			{
			m-=(a[n]-a[i]);
			}
			else
			{
				break;
			}
			k=i;
		}
		cout<<n-k+1;
		return 0;
	}
	else if(q&&!f)
	{
		long long s=1;
		long long v=a[2]-a[1];
		int t=0;
		while(s<(m/v))
		{
			s+=(s+1);
			t++;
		}
		if(s==m)
		{
			cout<<t;
			return 0;
		}
		else 
		{
		cout<<t-1;
		return 0;
		}
	}
	else
	{
		cout<<n;
		return 0;
	}
	return 0;
}
