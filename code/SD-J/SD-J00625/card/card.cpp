#include<bits/stdc++.h>
using namespace std;

int n,a[500005],c[500005],m;
int vis[300005],ans[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = n;i >= 1;i--)
	{
		if(vis[a[i]] == 0)
		{
			vis[a[i]] = i;
		}
		else
		{
			c[i] = vis[a[i]];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		bool vis2[300005] = {};
		for(int j = i;j <= n;j++)
		{
			if(!vis2[a[j]])
			{
				vis2[a[j]] = 1;
				ans[a[j]]++;
			}
			if(c[j] != 0)
			{
				j = c[j];
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
