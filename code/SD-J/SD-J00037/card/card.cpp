#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005]={0},n,m,bl=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int g=0;g<bl;g++)
			{
				if(b[g]==a[j])
				{
					bl=g;
					break;
				}
			}
			b[bl]=a[j];
			bl++;
		}
		for(int j=0;j<bl;j++)
		{
			c[b[j]]++;
		}
		bl=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
}
