#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],c[100005],ans[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]==0)
			{
				c[a[j]]=1;
			}
			else
			{
				for(int k=j-1;k>=1;k--)
				{
					if(a[k]==a[j])
					{
						cnt=k;
						break;
					}
				}
				for(int k=cnt;k<=j;k++)
				{
					c[a[k]]=0;
				}
				c[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=c[j];
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}