#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000],b[1000000],c[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j-1;k>i;k--)
			{
				if(a[j]==a[k])
				{
					for(int x=1;x<j;x++)
					{
						b[x]=0;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(b[k]==j)
				{
					c[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
