#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[500005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int begin=i;
		for(int j=i;j<=n;j++)
		{
			bool flag=false;
			c[j]=a[j];
			for(int x=begin;x<j;x++)
			{
				if(a[x]==a[j])
				{
					begin=x;
					flag=true;
					break;
				}
			}
			if(flag)
			{
				for(int x=begin;x<j;x++)
				{
					c[x]=0;
				}
				begin=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			d[c[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(d[j]>1)
				d[j]=1;
			b[j]+=d[j];
		}
		for(int j=0;j<=n;j++)
		{
			c[j]=0;
			d[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
