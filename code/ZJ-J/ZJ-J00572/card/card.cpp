#include <bits/stdc++.h>
using namespace std;
int n,m,an[500005],am[300005],c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>an[i];
		c[i]=i;
		for(int j=i-1;j>=1;j--)
		{
			if(an[i]==an[j])
			{
				c[j]=0;
				for(int k=j+1;k<=i-1;k++)
				{
					c[k]=min(k-j,c[k]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		am[an[i]]+=c[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<am[i]<<" ";
	}
	return 0;
}