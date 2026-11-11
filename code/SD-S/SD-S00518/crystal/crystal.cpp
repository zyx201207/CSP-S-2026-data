#include<bits/stdc++.h>
using namespace std;
long long n,m,f[500005],sum=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		  cin>>f[i];
		sort(f+1,f+n+1);
		for(int i=1;i<=n;i++)
		{
			long long s=0,ans=0;
			for(int j=i;j>=1;j--)
			{
			   	s+=f[i]-f[j];
			   	if(s>m)
			   	  break;
			   	ans++;
			}
			sum=max(sum,ans);
		}
		cout<<sum;
	}
	else
	{
		long long a=1,p;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			if(i==2)
			p=f[2]-f[1];
			if(i>=2&&f[i]-f[i-1]!=p)
			  a=0;
		}
		if(a)
		{
			long long s=0,ans=0;
			for(int i=n;i>=1;i--)
			{
				s+=(n-i)*p;
				if(s<=m)
				{
					ans++;
				}
				else
				{
					break;
				}
			}
			cout<<ans;
		}
		else
		{
			cout<<n; 
		} 
	}
	return 0;
} 
