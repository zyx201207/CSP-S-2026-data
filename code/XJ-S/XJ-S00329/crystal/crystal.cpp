#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005];
int main()
{
	freopen("crystal.in","r",stdout);
	freopen ("crystal.out","w",stdint);
	int n,m,sum=0,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		sum=0;
		for (int j=1;j<=n;j++)
		{
			if (a[i]>a[j])
			{
				if (a[j]+m>=a[i])
				{
					for (int z=1;z<=m;z++)
					{
						if (a[j]+z==a[i])
						{
							m=m-z;
							sum++;
						}
					}
				}
			}
			if(a[i]==a[j]) 
			{
				sum++;
			}
		}
		b[i]=sum;
	}
	for (int i=1;i<=n;i++)
	{
		if (maxn<b[i])
		{
			maxn=b[i];
		}
	}
	maxn=maxn+1;
	cout<<maxn;
	return 0;
}
