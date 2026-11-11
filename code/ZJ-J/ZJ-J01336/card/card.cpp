#include<bits/stdc++.h>
using namespace std;
long long n,m,a[511000],b[511000],c[511000],k,l;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int y=i;y<=n;y++)
		{
			for(int j=1;j<=k;j++)
			{
				if(b[j]==a[y])
				{
					for(int l=j;l<=k;l++)
					{
						b[l]=0;
					}
					k=j-1;
				}
			}
			b[++k]=a[y];
		}
		
		for(int j=1;j<=k;j++)
		{
			c[b[j]]++;
			b[j]=0;
		}
		k=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
