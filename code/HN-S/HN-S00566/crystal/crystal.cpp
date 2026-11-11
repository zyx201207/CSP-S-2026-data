#include<bits/stdc++.h>
using namespace std;

long long a[1000000000005]; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long d=a[n/2+1];
	long long ans=0;
	for(long long i=n;i>=1;i--)
	{
		if(a[i]==a[n/2+1])
		{
			ans++;
		}
		if(a[i]<a[n/2+1])
		{
			for(long long j=1;j<=m;j++)
			{
				if(a[i]==a[n/2+1])
				{
					ans++;
					break;
				}
				else
				{
					a[i]++;
					m--;
				}
			}
			if(m==0)
			{
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
