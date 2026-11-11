#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int b[n+10]={1};
	int f[m+10]={0};
	for(int u=1;u<=n;u++)
	{
		for(int i=u;i<=n;i++)
		{
			b[i]=1;
		}
		for(int i=1;i<u;i++)
		{
			b[i]=0;
		}
		for(int y=u;y<=n;y++)
		{
			for(int i=y+1;i<=n;i++)
			{
				if(a[y]==a[i]&&b[y]==1)
				{
					for(int j=y;j<=i-1;j++)
					{
						b[j]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i])
			{
				f[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
