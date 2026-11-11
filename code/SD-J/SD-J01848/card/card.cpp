#include<bits/stdc++.h>
using namespace std;
int a[200005],b[300005],c[200005],f2[300005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]=i;
	}
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(a[n]<a[n-1])
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f2[j]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(f2[a[j]]==1)
				{
					continue;
				}
				else
				{
					d[a[j]]++;
					f2[a[j]]=1;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<d[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int maxc=i;
		for(int j=1;j<=m;j++)
		{
			f2[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(f2[a[j]]==1)
			{
				maxc=max(maxc,c[a[j]]);
			}
			else
			{
				f2[a[j]]=1;
			}
		}
		for(int j=maxc;j<=n;j++)
		{
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
