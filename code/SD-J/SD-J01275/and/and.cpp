#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
	    long long ans=-2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=ans)
			{
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		long long ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		long long ans=a[1],cnt=-1;
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(ans&a[i]>=cnt)
			{
				cnt=ans&a[i];
			}
		}
		cout<<cnt;
		return 0;
	}
	
	return 0;
 } 
