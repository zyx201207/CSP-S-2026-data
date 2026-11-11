#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[100000000],z;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if (n==m)
	{
		int ans=a[2]&a[1];
		for (int i=3;i<=m;i++) 
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if (m==1)
	{
		cout<<a[n];
		return 0;
	}
	if (m==2)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (j!=i)
				{
					int ma=a[i]&a[j];
					ans=max(ma,ans);
				}
				 
			}
		}
		cout<<ans;
		return 0;
	}
	if (m==3)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
					if (j!=i and i!=k and k!=j)
					{
						int ma=a[i]&a[j]&a[k];
						ans=max(ma,ans);
					} 
			}
		}
		cout<<ans;
		return 0;
	}
	if (m==n-1)
	{
		int ans=0;
		for (int i=1;i<n;i++)
		{
			int noww=a[n];
			for (int j=1;j<=n;j++)
			{
				if (j!=i)
				{
					noww=noww&a[j];
				}
			}
			ans=max(ans,noww);
		}
		int noww=a[1];
		for (int j=2;j<n;j++)
		{
			noww=noww&a[j];
		}
		ans=max(ans,noww);
		cout<<ans;
		return 0;
	}
	return 0;
 } 
