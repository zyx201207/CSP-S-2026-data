#include<bits/stdc++.h>
using namespace std;
int n,a[1001],m,c[1001][1001],q,min[101];
int	num[1001],k[1001],m1[1001];
int main()
{
	cin>>n>>m;
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				q=a[i];
				a[i]=a[j];
				a[j]=q;	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		c[i][i]=0;
		for(int j=i+1;j<=n;j++)
		{
			c[i][j]=a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(num[i]<=5)
			{
				num[i]+=c[i][j];
			}
			else
			{
				k[i]=j-1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(k[i]==a[j])
			{
				num[a[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(num[i]>num[j])
			{
				q=num[i];
				num[i]=num[j];
				num[j]=q;	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
		}
	}
	return 0;
 } 
