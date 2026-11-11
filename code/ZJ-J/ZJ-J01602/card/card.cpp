#include<bits/stdc++.h>
using namespace std;
int a[500000],b[500000],da[5000][5000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=1;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			b[l]=a[i];
			l++;
			for(int j=i;j>=k;j--)
			{
				if(a[j]==a[i])
				{
					for(int k=j;k<=n;k++)
					{
						b[j]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			da[k][i]=b[i];
		}
		memset(b,0,sizeof(b));
		l=1;
	}
	for(int i=1;i<=m;i++)
	{
		int s=0;
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(da[j][k]==i)
				{
					s++;
				}
			}
		}
		cout<<s<<" ";
	}
	return 0;
}
