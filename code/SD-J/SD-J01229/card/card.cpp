#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
		int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			c[j]=a[j];
			bool pd=0;
			for(int z=i;z<j;z++)
			{
				if(c[z]==c[j]&&c[z]!=0&&c[j]!=0&&z!=j)
				{
					pd=1;
				}
				if(pd==1)
				{
					c[z]=0;
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			b[c[j]]++;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 
