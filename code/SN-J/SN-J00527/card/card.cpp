#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],p[500005];
int x[300005],y[300005];
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
			x[a[j]]++;
			
			if(x[a[j]]==2)
			{
				for(int k=p[a[j]];k<j;k++)
				{
					x[a[k]]=0;
				}
				x[a[j]]=1;
			}
			p[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			y[j]+=x[j];
			
			x[j]=0;
			p[j]=0;
		}
	}
	y[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<y[i]<<" ";
	}
	return 0;
}
