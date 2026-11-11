#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[1000000005]={},sum[m+5]={},tot[m+5]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int b[100000005]={};
		for(int j=i;j<=n;j++)
		{
			
			if(sum[a[j]]==0)
			{
				b[j-i]=a[j];
				sum[a[j]]++;
			}
			else 
			{
				for (int i=1;i<=m;i++)
				{
					b[i]=0;
				}
	
				b[1]=a[j];
			}
		}
		for (int i=1;i<=m;i++)
		{
			if(b[i]!=0) tot[b[i]]++;
		}
	
	}
	for(int i=1;i<=m;i++)
	{
		cout <<tot[i]<<" ";
	}
	return 0;
	
}
