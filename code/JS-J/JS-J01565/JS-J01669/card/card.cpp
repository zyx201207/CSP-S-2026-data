#include <bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
struct node
{
	int cntt=0;
	int first=0;
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	memset(a,0,sizeof(a));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		node cnt[200010]={{0,0}};
		bool vis[200010];
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;++j)
		{
			if(cnt[a[j]].cntt!=0)
			{
				for(int k=cnt[a[j]].first;k<=j-1;++k)
				{
					vis[k]=1;
					cnt[a[k]].cntt=0;
				}
			}
			cnt[a[j]].cntt=1;
			cnt[a[j]].first=j;
		}
		for(int j=i;j<=n;++j)
		{
			if(vis[j]==0) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
