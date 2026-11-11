#include<bits/stdc++.h>
using namespace std;
int a[10000],b[300000],c[300000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m ;
	cin >> n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int pd=0;
			for(int o=1;o<=sum;o++)
			{
				if(a[j]==b[o])
				{
					pd=1;
					continue;
				}
			}
			if(pd==1)
			{
				for(int s=1;s<=sum;s++)
				{
					b[s]=0;
				}
				sum=0;
			}
			b[sum+1]=a[j];
			sum++;
		}
		for(int u=1;u<=sum;u++)
		{
			c[b[u]]++;
		}
		for(int s=1;s<=sum;s++)
		{
					b[s]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
