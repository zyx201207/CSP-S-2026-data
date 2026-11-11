#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],maxn=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		int maxn1=-1e9;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn1=max(maxn1,a[i]&a[j]);
			}
		}
		cout<<maxn1;
		return 0;
	}
	if(m==3)
	{
		int maxn1=-1e9;
		for(int i=1;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					maxn1=max(maxn1,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<maxn1;
		return 0;
	}
	if(m==4)
	{
		int maxn1=-1e9;
		for(int i=1;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					for(int p=k+1;p<=n;p++)
					{
						maxn1=max(maxn1,a[i]&a[j]&a[k]&a[p]);
					}
				}
			}
		}
		cout<<maxn1;
		return 0;
	}
	if(m==5)
	{
		int maxn1=-1e9;
		for(int i=1;i<n-3;i++)
		{
			for(int j=i+1;j<n-2;j++)
			{
				for(int k=j+1;k<n-1;k++)
				{
					for(int p=k+1;p<n;p++)
					{
						for(int s=p+1;s<=n;s++)
						maxn1=max(maxn1,a[i]&a[j]&a[k]&a[p]&a[s]);
					}
				}
			}
		}
		cout<<maxn1;
		return 0;
	}
	return 0;
}
