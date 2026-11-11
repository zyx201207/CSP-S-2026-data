#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],p[500005],k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int t=1;t<=n;t++)
	{
		k=0;
		memset(p,0,sizeof(p));
		for(int i=t;i<=n;i++)
		{
			p[++k]=a[i];
			for(int j=1;j<k;j++)
			{
				if(p[j]==p[k])
				{
					k=j;
					break;
				}
			}
		}
		for(int i=1;i<=k;i++)
		{
			sum[p[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
