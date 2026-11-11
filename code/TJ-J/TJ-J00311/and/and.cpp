#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[200005],m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	if(m==2)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	if(m==n-1)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int cnt=a[1];
			if(i==1)
			{
				int cnt=a[2];
			}
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				cnt=cnt&a[j];
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
