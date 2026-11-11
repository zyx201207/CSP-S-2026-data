#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],c[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			c[j]=a[j];
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				if(c[j]==c[k])
				{
					for(int l=k;l>j;l--)
						c[l]=0;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(c[j]!=0) 
				b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
