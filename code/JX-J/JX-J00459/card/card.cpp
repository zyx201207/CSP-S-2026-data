#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[600001],b[400001]={0},c[400001]={0},d[400001]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			if(b[a[i]]==0)
			{
				b[a[i]]=1;
				d[a[i]]=i;
			}
			else
			{
				for(int k=d[a[i]];k<=i;k++)
				{
					b[a[k]]=0;
				}
				b[a[i]]=1;
				d[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(b[i]==1)
			{
				b[i]=0;
				c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
