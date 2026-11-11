#include<iostream>
using namespace std;
int a[500005],b[300005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]<=a[i])
			z++;
	}
	if(z==n)
	{
		int x=0;
		for(int i=2;i<=n;i++)
		{
			x++;
			if(a[i-1]!=a[i])
				cout<<x<<" ";
		}
		cout<<x+1<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
				b[a[j]]=j;
			else
			{
				int l=b[a[j]];
				for(int k=1;k<m;k++)
				{
					if(b[k]>=l&&b[k]<j)
						b[k]=0;
				}
				b[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]!=0)
				c[j]++;
		}
		for(int j=1;j<=m;j++)
			b[j]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}
