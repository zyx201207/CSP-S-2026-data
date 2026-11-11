#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],c[500001],cnt,ans[30001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		c[1]=a[j];
		cnt=1;
		for(int i=j;i<=n;i++)
		{
			for(int k=1;k<=cnt;k++)
			{
				if(c[k]==a[i+1])
				{
					
					for(int t=k;t<=cnt;t++)
					{
						c[t]=0;
					}
					cnt=cnt-k-1;
				}
			}
			c[cnt+1]=a[i+1];
			cnt++;
		}
		for(int i=1;i<=cnt;i++)
		{
			ans[c[i]]++;
			c[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
