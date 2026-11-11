#include<bits/stdc++.h>
using namespace std;
const int N=600000;
int a[N];
int min=500005;
int shu[N];
int zui[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,x=1,lin=0,max=0,zhuan=0;
	cin>>n>>m;
	///////////////////////////////////////////////
	for(int u=1;u<=n;u++)
	{
		cin>>a[u];
	}
	///////////////////////////////////////////////
	for(int i=1;i<=n;i++)
	{
		x=1;
		zui[i]=1;
		for(int j=1;j<=n;j++)
		{
			if(j!=i&&a[j]<=a[i])
			{
				zhuan=a[i]-a[j];
				shu[x]=zhuan;
				x++;
			}
		}
		if(x!=1)
		{
			lin=m;
			for(int k=1;k<x;k++)
			{
				for(int l=1;l<=x-1;l++)
				{
					if(shu[l]>shu[l+1])
					{
						swap(shu[l],shu[l+1]);
					}
				}
			}
			for(int q=1;q<x;q++)
			{
				if(shu[q]==0)
				{
					zui[i]=zui[i]+1;
				}
				else if(lin-shu[q]>=0)
				{
					lin=lin-shu[q];
					zui[i]=zui[i]+1;
				}
			}		
		}
	}
	//////////////////////////////////////////////
	int y=1;
	while(y<=n)
	{
		if(zui[y]>=max)
		{
			max=zui[y];
		}
		y++;
	}
	cout<<max;
	return 0;
}
