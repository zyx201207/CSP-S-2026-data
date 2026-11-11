#include <bits/stdc++.h>
using namespace std;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	bool fl=1;
	long long avg=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2&& a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			fl=0;
		}
	}
	if(fl)
	{
		int ans=1;
		while(m>0)
		{
			if(m-ans*(a[2]-a[1])>0)
			{
				m-=ans*(a[2]-a[1]);
				ans++;
			}else
			{
				cout<<ans;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		avg+=a[i];
	}
	avg=(avg+m)/n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=avg)
		{
			ans++;
		}
		
	}
	cout<<ans;
	
	return 0;
}
