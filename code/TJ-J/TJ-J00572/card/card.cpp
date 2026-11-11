#include <bits/stdc++.h>
using namespace std;
int b[500010];
int a[1000010];
int sum[300010];
void si(int x)
{
	int q = 1;
	bool ls=1;
	while(q<x)
	{
		if(ls)
		{
			for(int i = x;i>q;)
			{
				if(ls)
				{
					if(a[q]==a[i])
					{
						ls=0;
						for(int j= 1;j<=q-1;j++)
						{
							sum[a[j]]++;
						}
						for(int j= i;j<=x+1;j++)
						{
							sum[a[j]]++;
						}
						
					}
				}
				i--;
			}
		}
			
		q++;
	}
	if(ls)
	{
		for(int i= 1;i<=x;i++)
		{
			sum[a[i]]++;
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i= 1;i<=n;i++)
	{
		cin>>b[i];
	}
	int zz = 1;
	for(int i= 1;i<=n;i++)
	{
		for(int j= 1;j<=i;j++)
		{
			a[zz]=b[j];
			zz++;
		}
		
	}
	for(int i= 1;i<=zz-1;i++)
	{
		si(i);
	}
	for(int i= 1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
} 
