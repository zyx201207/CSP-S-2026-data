#include<bits/stdc++.h>
using namespace std;
int a[500005];
int d[500005];
int b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool g=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
		{
			g=0;
		}
	}
	if(g)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int l=1;l<=n;l++)
	{
		int k=0;
		for(int i=l;i<=n;i++)
		{
			int j=1;
			while(j<=k&&d[j]!=a[i])
			{
				j++;
			}
			k=j;
			d[k]=a[i];
		}
		for(int i=1;i<=k;i++)
		{
			b[d[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
