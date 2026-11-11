#include<bits/stdc++.h>
using namespace std;
int a[500007],cnt[200007],g[200007],d[200007];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[j]=a[j];
			cnt[a[j]]=0;
		}
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
		}
		for(int j=i;j<=n;j++)
		{
			if(cnt[d[j]]!=0)
			{
				for(int k=j;k<=n;k++)
				{
					if(d[k]==d[j]&&k!=j)
					{
						for(int l=j;l<k;l++)
						{
							if(d[l]!=0)cnt[d[l]]--;
							d[l]=0;
						}
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			g[j]+=cnt[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<g[i]<<' ';
	}
	return 0;
}